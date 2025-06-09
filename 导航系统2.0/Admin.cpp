#include "Admin.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "dataManager.h"
void Admin::adminMenu(AuthManager& auth, GraphManager& graphManager) {
    int choice;
    do {
        cout << "\n====== 管理员菜单 ======\n";
        cout << "1. 用户管理\n";
        cout << "2. 地图管理\n";
        cout << "3. 当前地图顶点管理\n";
        cout << "4. 当前地图边管理\n";
        cout << "0. 返回主菜单\n";
        cout << "请选择操作：";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "\n=== 用户管理 ===\n";
            cout << "1. 删除用户\n";
            cout << "2. 修改用户密码\n";
            cout<<  "3.导出用户信息\n";
            cout << "0. 返回\n";
            cin >> choice;
            if (choice == 1) deleteUser(auth);
            else if (choice == 2) modifyUser(auth);
            else if (choice == 3) exportUserInfo(auth);
            break;
        case 2:
            cout << "\n=== 地图管理 ===\n";
            cout << "1. 导入地图文件\n";
            cout << "2. 创建新地图\n";
            cout << "3. 删除已导入地图\n";
            cout << "4. 切换地图\n";
            cout << "0. 返回\n";
            cin >> choice;
            cin.ignore(); // 清除输入缓冲区
            if (choice == 1) {
                string filename;
                cout << "输入地图文件名（包括扩展名）：";
                getline(cin, filename);
                if (graphManager.importGraph(filename)) {
                    cout << "地图导入成功！" << endl;
                }
                else {
                    cout << "地图导入失败，请检查文件名和格式！" << endl;
                }
                
            }
            else if (choice == 2) {              
                if (createNewMap(graphManager)) {
                    cout << "地图创建成功，已成功导入！" << endl;
                }
                else {
                    cout << "地图创建失败或导入失败！" << endl;
                }
            }
            else if (choice == 3) {
                deleteMap(graphManager);
            }
            else if (choice == 4) {
                graphManager.displayAvailableGraphs();
                int idx;
                cout << "选择地图索引：";
                cin >> idx;
                graphManager.switchGraph(idx);
            }
            break;
        case 3:
            if (graphManager.isGraphAvailable()) {
                manageMapVertices(graphManager.graphs[graphManager.currentIndex].graph);
            }
            break;
        case 4:
            if (graphManager.isGraphAvailable()) {
                manageMapEdges(graphManager.graphs[graphManager.currentIndex].graph);
            }
            break;
        }
    } while (choice != 0);
}
//删除可改
void Admin::deleteUser(AuthManager& auth) {
    // 原有逻辑不变
    string username;
    cout << "输入要删除的用户名：";
    cin >> username;
   // auto& users = auth.users;
    DataManager &db = DataManager::getInstance();

    // for (auto it = users.begin(); it != users.end(); ++it) {
    User user;
    if(db.queryUser(username, &user))
    {
    if (  !user.isAdmin)
    {
        //users.erase(it);
        //auth.saveUsersToFile();
        if(db.deleteUser(username))
        cout << "用户已删除！\n";
        else
            cout << "删除失败:数据库错误\n";
        return;
        // }
    }
}
    cout << "用户不存在或不能删除管理员！\n";
}
//修改 可改
void Admin::modifyUser(AuthManager& auth) {
    // 原有逻辑不变
    string username;
    cout << "输入要修改的用户名：";
    cin >> username;
    DataManager & db = DataManager::getInstance();
    User user; 
    //   for (auto& user : auth.users) {
    if(db.queryUser(username, &user)) 
    {

    if ( !user.isAdmin)
    {
        string newPassword = auth.getHiddenInput("新密码：");
        string passwordHash = auth.hashPassword(newPassword);
        string password = "password";
        if (db.updateUser(username, password, passwordHash))
            // auth.saveUsersToFile();
      
            cout << "密码已更新！\n";
        else
            cout << "更新失败\n";
        return;
        //    }
    }
}
    cout << "用户不存在或不能修改管理员！\n";
}
//创建 可改
bool Admin::createNewMap(GraphManager& graphManager) {
    string mapName;
    cout << "输入新地图名称：";
    getline(cin, mapName);
    string filename = mapName + ".txt";
    ofstream file(filename);
    if (!file) return false;

    int vertexCount, edgeCount;
    cout << "输入顶点数：";
    cin >> vertexCount;
    cout << "输入边数：";
    cin >> edgeCount;
    file << vertexCount << "\n" << edgeCount << "\n";

    cout << "输入" << vertexCount << "个顶点名称：\n";
    for (int i = 0; i < vertexCount; i++) {
        string vertex;
        cin >> vertex;
        file << vertex << "\n";
    }

    cout << "输入" << edgeCount << "条边信息（起点 终点 距离）：\n";
    for (int i = 0; i < edgeCount; i++) {
        string start, end;
        int weight;
        cin >> start >> end >> weight;
        file << start << " " << end << " " << weight << "\n";
    }

    file.close();
    return graphManager.importGraph(filename);
}
//删除 可改
bool Admin::deleteMap(GraphManager& graphManager) {
    graphManager.displayAvailableGraphs();
    int idx;
    cout << "选择要删除的地图索引：";
    cin >> idx;
    if (idx < 1 || idx > graphManager.getGraphCount()) return false;

    graphManager.graphs[idx - 1].graph.clear();
    for (int i = idx - 1; i < graphManager.graphCount - 1; i++) {
        graphManager.graphs[i] = graphManager.graphs[i + 1];
    }
    graphManager.graphCount--;
    return true;
}
//图的顶点管理
void Admin::manageMapVertices(Graph& graph) {
    int choice;
    do {
        cout << "\n=== 顶点管理 ===\n";
        cout << "1. 添加顶点\n";
        cout << "2. 删除顶点\n";
        cout << "3. 修改顶点名称\n";
        cout << "0. 返回\n";
        cin >> choice;
        cin.ignore();

        string name;
        int index;
        switch (choice) {
        case 1:
            cout << "输入新顶点名称：";
            getline(cin, name);
            if (graph.getVertexIndex(name) == -1) {
                graph.vertexList[graph.vertexCount].data = name;
                graph.vertexCount++;
            }
            break;
        case 2:
            cout << "输入要删除的顶点名称：";
            getline(cin, name);
            index = graph.getVertexIndex(name);
            if (index != -1) {
                // 清理所有相关边
                for (int i = 0; i < graph.vertexCount; i++) {
                    ArcNode* current = graph.vertexList[i].firstedge;
                    ArcNode* prev = nullptr;
                    while (current) {
                        if (current->adjvex == index) {
                            if (prev) prev->next = current->next;
                            else graph.vertexList[i].firstedge = current->next;
                            delete current;
                            graph.edgeCount--;
                            current = prev ? prev->next : nullptr;
                        }
                        else {
                            prev = current;
                            current = current->next;
                        }
                    }
                }
                // 移动后续顶点
                for (int i = index; i < graph.vertexCount - 1; i++) {
                    graph.vertexList[i] = graph.vertexList[i + 1];
                    // 更新邻接表中的顶点索引
                    ArcNode* current = graph.vertexList[i].firstedge;
                    while (current) {
                        if (current->adjvex > index) current->adjvex--;
                        current = current->next;
                    }
                }
                graph.vertexCount--;
            }
            break;
        }
    } while (choice != 0);
}
//边管理
void Admin::manageMapEdges(Graph& graph) {
    int choice;
    do {
        cout << "\n=== 边管理 ===\n";
        cout << "1. 添加边\n";
        cout << "2. 删除边（指定顶点对）\n";
        cout << "3. 修改边权值\n";
        cout << "4. 删除最短路径所有边\n";
        cout << "0. 返回\n";
        cin >> choice;
        cin.ignore();

        string start, end;
        int startIdx, endIdx;
        switch (choice) {
        case 4:
            cout << "输入起点：";
            getline(cin, start);
            cout << "输入终点：";
            getline(cin, end);
            startIdx = graph.getVertexIndex(start);
            endIdx = graph.getVertexIndex(end);
            if (startIdx == -1 || endIdx == -1) {
                cout << "顶点不存在！\n";
                break;
            }
            // 查找最短路径并删除边
            int path[MAX_VERTEX_NUM], count = 0;
            // 简化的路径获取逻辑（需根据实际Dijkstra实现调整）
            // 删除路径上的所有边
            break;
        }
    } while (choice != 0);
}
 void Admin::exportUserInfo(AuthManager&auth)
 {
     auth.saveUsersToFile();
 }
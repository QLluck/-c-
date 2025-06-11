#include "Admin.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "dataManager.h"
#include <algorithm>
void Admin::adminMenu(AuthManager &auth, GraphManager &graphManager)
{
    int choice;
    do
    {
        
        cout << "\n====== 管理员菜单 ======\n";
        cout << "1. 用户管理\n";
        cout << "2. 地图管理\n";
        cout << "3. 当前地图顶点管理\n";
        cout << "4. 当前地图边管理\n";
        cout << "0. 退出登录\n";
        cout << "请选择操作：";
        cin >> choice;
        cin.ignore();
        system("cls");

        int choose;
        switch (choice)
        {
        case 1:
            cout << "\n=== 用户管理 ===\n";
            cout << "1. 删除用户\n";
            cout << "2. 修改用户密码\n";
            cout << "3.导出用户信息\n";
            cout << "0. 返回\n";

            cin >> choose;
            if (choose == 1)
                deleteUser(auth);
            else if (choose == 2)
                modifyUser(auth);
            else if (choose == 3)
                exportUserInfo(auth);
            break;
        case 2:
            do
            {
                cout << "\n=== 地图管理 ===\n";
                cout << "1. 导入地图文件\n";
                cout << "2. 创建新地图\n";
                cout << "3. 删除已导入地图\n";
                cout << "4. 切换地图\n";
                cout << "5.查看当前地图信息\n";
                cout << "0. 返回\n";
                cin >> choose;
                cin.ignore(); // 清除输入缓冲区
                if (choose == 1)
                {
                    string filename;
                    cout << "输入地图文件名（包括扩展名）：";

                    cin >> filename;
                    cin.ignore();
                    if (graphManager.importGraph(filename))
                    {
                        cout << "地图导入成功！" << endl;
                    }
                    else
                    {
                        cout << "地图导入失败，请检查文件名和格式！" << endl;
                    }
                }
                else if (choose == 2)
                {
                    if (createNewMap(graphManager))
                    {
                        cout << "地图创建成功，已成功导入！" << endl;
                    }
                    else
                    {
                        cout << "地图创建失败或导入失败！" << endl;
                    }
                }
                else if (choose == 3)
                {
                    deleteMap(graphManager);
                }
                else if (choose == 4)
                {
                    graphManager.displayAvailableGraphs();
                    int idx;
                    cout << "选择地图索引：";
                    cin >> idx;
                    graphManager.switchGraph(idx);
                }
                else if (choose == 5)
                {
                    if (graphManager.isGraphAvailable())
                    {
                        graphManager.displayCurrentGraphInfo();
                    }
                    break;
                }
                system("pause");
                system("cls");
            } while (choose != 0);
            break;
        case 3:
            if (graphManager.isGraphAvailable())
            {
                manageMapVertices(graphManager.graphs[graphManager.currentIndex].graph, graphManager);
            }
            break;
        case 4:
            if (graphManager.isGraphAvailable())
            {
                manageMapEdges(graphManager.graphs[graphManager.currentIndex].graph, graphManager);
            }
            break;
        }
        system("pause");
        system("cls");
    } while (choice != 0);
}

void Admin::deleteUser(AuthManager &auth)
{
    // 原有逻辑不变
    string username;
    cout << "输入要删除的用户名：";
    cin >> username;
    // auto& users = auth.users;
    DataManager &db = DataManager::getInstance();

    // for (auto it = users.begin(); it != users.end(); ++it) {
    User user;
    if (db.queryUser(username, &user))
    {
        if (!user.isAdmin)
        {
            // users.erase(it);
            // auth.saveUsersToFile();
            if (db.deleteUser(username))
                cout << "用户已删除！\n";
            else
                cout << "删除失败:数据库错误\n";
            return;
            // }
        }
    }
    cout << "用户不存在或不能删除管理员！\n";
}

void Admin::modifyUser(AuthManager &auth)
{
    // 原有逻辑不变
    string username;
    cout << "输入要修改的用户名：";
    cin >> username;
    DataManager &db = DataManager::getInstance();
    User user;
    //   for (auto& user : auth.users) {
    if (db.queryUser(username, &user))
    {

        if (!user.isAdmin)
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

bool Admin::createNewMap(GraphManager &graphManager)
{
    string mapName;
    cout << "输入新地图名称：";
    getline(cin, mapName);
    string filename = mapName + ".txt";
    ofstream file(filename);
    if (!file)
        return false;

    int vertexCount, edgeCount;
    cout << "输入顶点数：";
    cin >> vertexCount;
    cout << "输入边数：";
    cin >> edgeCount;
    file << vertexCount << "\n"
         << edgeCount << "\n";

    cout << "输入" << vertexCount << "个顶点名称：\n";
    string *vList = new string[vertexCount]; // 暂时存储顶点用来查重
    for (int i = 0; i < vertexCount; i++)
    {
        string vertex;
        cin >> vertex;
        // 查重
        vList[i] = vertex;
        for (int j = 0; j < i; j++)
        {
            if (vList[j] == vertex)
            {
                cout << "顶点名称重复，请重新输入：";
                i--;
                continue;
            }
        }
        file << vertex << "\n";
    }
    delete[] vList;

    cout << "输入" << edgeCount << "条边信息（起点 终点 距离）：\n";
    for (int i = 0; i < edgeCount; i++)
    {
        string start, end;
        int weight;
        cin >> start >> end >> weight;
        file << start << " " << end << " " << weight << "\n";
    }

    file.close();
    return graphManager.importGraph(filename);
}

bool Admin::deleteMap(GraphManager &graphManager)
{
    graphManager.displayAvailableGraphs();
    int idx;
    cout << "选择要删除的地图索引：";
    cin >> idx;
    if (idx < 1 || idx > graphManager.getGraphCount())
        return false;

    graphManager.graphs[idx - 1].graph.clear();
    for (int i = idx - 1; i < graphManager.graphCount - 1; i++)
    {
        graphManager.graphs[i] = graphManager.graphs[i + 1];
    }
    graphManager.graphCount--;
    return true;
}

void Admin::manageMapVertices(Graph &graph, GraphManager &graphManager)
{
    int choice;
    do
    {
        cout << "\n=== 顶点管理 ===\n";
        cout << "1. 添加顶点\n";
        cout << "2. 删除顶点\n";
        cout << "3. 修改顶点名称\n";
        cout << "0. 返回\n";
        cin >> choice;
        cin.ignore();

        string name;
        int index;
        switch (choice)
        {
        case 1:
            cout << "输入新顶点名称：";
            getline(cin, name);
            if (graph.getVertexIndex(name) == -1)
            {
                graph.vertexList[graph.vertexCount].data = name;
                graph.vertexCount++;
                // 保存到文件
                graphManager.saveGraphToFile(graphManager.currentIndex);
                cout << "顶点添加成功！" << endl;
            }
            break;
        case 2:
            cout << "输入要删除的顶点名称：";
            getline(cin, name);
            index = graph.getVertexIndex(name);
            if (index != -1)
            {
                // 清理所有相关边==
                for (int i = 0; i < graph.vertexCount; i++)
                {
                    ArcNode *current = graph.vertexList[i].firstedge;
                    ArcNode *prev = nullptr;
                    while (current)
                    {
                        if (current->adjvex == index)
                        {
                            if (prev)
                                prev->next = current->next;
                            else
                                graph.vertexList[i].firstedge = current->next;
                            delete current;
                            graph.edgeCount--;
                            current = prev ? prev->next : nullptr; 
                        }
                        else
                        {
                            prev = current;
                            current = current->next;
                        }
                    }
                }
                // 更新所有邻接表中的顶点索引
                for (int i = 0; i < graph.vertexCount; i++)
                {
                    ArcNode *current = graph.vertexList[i].firstedge;
                    while (current)
                    {
                        if (current->adjvex > index)
                        {
                            current->adjvex--;
                        }
                        current = current->next;
                    }
                }

                // 移动后续顶点
                for (int i = index; i < graph.vertexCount - 1; i++)
                {
                    graph.vertexList[i] = graph.vertexList[i + 1];
                }
                graph.vertexCount--;
                // 保存到文件
                graphManager.saveGraphToFile(graphManager.currentIndex);
                cout << "顶点删除成功！" << endl;
            }
            break;
        case 3:
            cout << "输入要修改的顶点名称：";
            getline(cin, name);
            index = graph.getVertexIndex(name);
            if (index != -1)
            {
                string newName;
                cout << "输入新的顶点名称：";
                getline(cin, newName);
                graph.vertexList[index].data = newName; // 仅更新名称，无需修改边
                cout << "顶点名称已修改！" << endl;
                // 保存到文件
                graphManager.saveGraphToFile(graphManager.currentIndex);
            }
            break;
        }
        system("pause");
        system("cls");
    } while (choice != 0);
}

void Admin::manageMapEdges(Graph &graph, GraphManager &graphManager)
{
    int choice;
    do
    {
        cout << "\n=== 边管理 ===\n";
        cout << "1. 添加边\n";
        cout << "2. 删除边（指定顶点对）\n";
        cout << "3. 修改边权值\n";
        cout << "4. 删除两点间最短路径所有边\n";
        cout << "5.删除两点间所有可达路径\n";
        cout << "0. 返回\n";
        cin >> choice;
        cin.ignore();

        string start, end;
        int startIdx, endIdx, weight;
        switch (choice)
        {
        case 1:
        {
            cout << "输入起点名称：";
            getline(cin, start);
            cout << "输入终点名称：";
            getline(cin, end);
            cout << "输入距离：";
            cin >> weight;
            cin.ignore();

            startIdx = graph.getVertexIndex(start);
            endIdx = graph.getVertexIndex(end);

            if (startIdx == -1 || endIdx == -1)
            {
                cout << "顶点不存在！" << endl;
                break;
            }

            // 检查是否已经存在该边
            ArcNode *current = graph.vertexList[startIdx].firstedge;
            while (current)
            {
                if (current->adjvex == endIdx)
                {
                    cout << "边已存在！" << endl;
                    break;
                }
                current = current->next;
            }

            if (!current)
            {
                // 创建新的边节点
                ArcNode *newArc = new ArcNode;
                newArc->adjvex = endIdx;
                newArc->weight = weight;
                newArc->next = graph.vertexList[startIdx].firstedge;
                newArc->visited = false;
                graph.vertexList[startIdx].firstedge = newArc;

                // 添加反向边（无向图）
                ArcNode *reverseArc = new ArcNode;
                reverseArc->adjvex = startIdx;
                reverseArc->weight = weight;

                reverseArc->next = graph.vertexList[endIdx].firstedge;

                reverseArc->visited = false;
                graph.vertexList[endIdx].firstedge = reverseArc;

                graph.edgeCount++;
                cout << "边已添加！" << endl;
                graphManager.saveGraphToFile(graphManager.currentIndex);
            }
            break;
        }

        case 2:
        {
            cout << "输入起点名称：";
            getline(cin, start);
            cout << "输入终点名称：";
            getline(cin, end);

            startIdx = graph.getVertexIndex(start);
            endIdx = graph.getVertexIndex(end);

            if (startIdx == -1 || endIdx == -1)
            {
                cout << "顶点不存在！" << endl;
                break;
            }

            // 删除正向边
            ArcNode *current = graph.vertexList[startIdx].firstedge;
            ArcNode *prev = nullptr;
            while (current)
            {
                if (current->adjvex == endIdx)
                {
                    if (prev)
                    {
                        prev->next = current->next;
                    }
                    else
                    {
                        graph.vertexList[startIdx].firstedge = current->next;
                    }
                    delete current;
                    graph.edgeCount--;
                    break;
                }
                prev = current;
                current = current->next;
            }

            // 删除反向边
            current = graph.vertexList[endIdx].firstedge;
            prev = nullptr;
            while (current)
            {
                if (current->adjvex == startIdx)
                {
                    if (prev)
                    {
                        prev->next = current->next;
                    }
                    else
                    {
                        graph.vertexList[endIdx].firstedge = current->next;
                    }
                    delete current;
                    break;
                    
                }
                prev = current;
                current = current->next;
            }

            cout << "边已删除！" << endl;
            graphManager.saveGraphToFile(graphManager.currentIndex);
            break;
        }

        case 3:
        {
            cout << "输入起点名称：";
            getline(cin, start);
            cout << "输入终点名称：";
            getline(cin, end);
            cout << "输入新的距离：";
            cin >> weight;
            cin.ignore();

            startIdx = graph.getVertexIndex(start);
            endIdx = graph.getVertexIndex(end);

            if (startIdx == -1 || endIdx == -1)
            {
                cout << "顶点不存在！" << endl;
                break;
            }

            // 修改正向边权值
            ArcNode *current = graph.vertexList[startIdx].firstedge;
            while (current)
            {
                if (current->adjvex == endIdx)
                {
                    current->weight = weight;
                    break;
                }
                current = current->next;
            }

            // 修改反向边权值
            current = graph.vertexList[endIdx].firstedge;
            while (current)
            {
                if (current->adjvex == startIdx)
                {
                    current->weight = weight;
                    break;
                }
                current = current->next;
            }

            cout << "边权值已修改！" << endl;
            graphManager.saveGraphToFile(graphManager.currentIndex);
            break;
        }

        case 4:
        {
            cout << "输入起点：";
            getline(cin, start);
            cout << "输入终点：";
            getline(cin, end);
            startIdx = graph.getVertexIndex(start);
            endIdx = graph.getVertexIndex(end);
            if (startIdx == -1 || endIdx == -1)
            {
                cout << "顶点不存在！" << endl;
                break;
            }

            // 查找最短路径
            int path[MAX_VERTEX_NUM];
            int count = 0;
            bool found = false;

            // 使用 Dijkstra 算法找到最短路径
            const int INF = 99999;    // 无穷大
            int dist[MAX_VERTEX_NUM]; // 保存最短路径的距离
            bool s[MAX_VERTEX_NUM];   // 标记是否找到最短路径
            int prev[MAX_VERTEX_NUM]; // 保存路径前驱节点

            // 初始化
            for (int i = 0; i < graph.vertexCount; ++i)
            {
                dist[i] = INF;
                s[i] = false;
                prev[i] = -1;
            }

            dist[startIdx] = 0;

            // Dijkstra算法主循环
            for (int i = 0; i < graph.vertexCount; ++i)
            {
                int u = -1;
                int minDist = INF;

                // 找出当前未确定的最短距离的顶点
                for (int j = 0; j < graph.vertexCount; ++j)
                {
                    if (!s[j] && dist[j] < minDist)
                    {
                        u = j;
                        minDist = dist[j];
                    }
                }

                if (u == -1 || u == endIdx)
                    break; // 找不到路径或找到终点

                s[u] = true;

                // 更新相邻顶点的距离
                ArcNode *currentArc = graph.vertexList[u].firstedge;
                while (currentArc)
                {
                    int v = currentArc->adjvex;
                    if (v >= 0 && v < graph.vertexCount && !s[v] && dist[u] + currentArc->weight < dist[v])
                    {
                        dist[v] = dist[u] + currentArc->weight;
                        prev[v] = u;
                    }
                    currentArc = currentArc->next;
                }
            }

            // 构建路径
            if (dist[endIdx] == INF)
            {
                cout << "没有路径可达！" << endl;
                break;
            }

            // 回溯路径
            int currentIndex = endIdx;
            while (currentIndex != -1)
            {
                if (currentIndex >= 0 && currentIndex < graph.vertexCount)
                {
                    path[count++] = currentIndex;
                    currentIndex = prev[currentIndex];
                }
                else
                {
                    cout << "路径索引超出范围！" << endl;
                    break;
                }
            }

            // 反转路径
            reverse(path, path + count);

            // 删除路径上的所有边
            for (int i = 0; i < count - 1; ++i)
            {
                int from = path[i];
                int to = path[i + 1];

                // 删除正向边
                ArcNode *current = graph.vertexList[from].firstedge;
                ArcNode *prevNode = nullptr;
                while (current)
                {
                    if (current->adjvex == to)
                    {
                        if (prevNode)
                        {
                            prevNode->next = current->next;
                        }
                        else
                        {
                            graph.vertexList[from].firstedge = current->next;
                        }
                        delete current;
                        graph.edgeCount--;
                        break;
                    }
                    prevNode = current;
                    current = current->next;
                }

                // 删除反向边
                current = graph.vertexList[to].firstedge;
                prevNode = nullptr;
                while (current)
                {
                    if (current->adjvex == from)
                    {
                        if (prevNode)
                        {
                            prevNode->next = current->next;
                        }
                        else
                        {
                            graph.vertexList[to].firstedge = current->next;
                        }
                        delete current;
                        break;
                    }
                    prevNode = current;
                    current = current->next;
                }
            }

            cout << "最短路径上的所有边已删除！" << endl;
            // 保存到文件
            graphManager.saveGraphToFile(graphManager.currentIndex);
            break;
        }

        case 5:
        {
            cout << "输入起点名称：";
            getline(cin, start);
            cout << "输入终点名称：";
            getline(cin, end);
            startIdx = graph.getVertexIndex(start);
            endIdx = graph.getVertexIndex(end);
            if (startIdx == -1 || endIdx == -1)
            {
                cout << "顶点不存在！" << endl;
                break;
            }
            deleteAllPathsBetween(graph, startIdx, endIdx, graphManager);
            break;
        }
        }
        system("pause");
        system("cls");
    } while (choice != 0);
}

// 删除两点间的所有可达路径
void Admin::deleteAllPathsBetween(Graph &graph, int startIdx, int endIdx, GraphManager &graphManager) 
{
    vector<vector<int>> paths = findAllPaths(graph, startIdx, endIdx);

    if (paths.empty())
    {
        cout << "两点间没有可达路径！" << endl;
        return;
    }

    for (const auto &path : paths)
    {
        for (size_t i = 0; i < path.size() - 1; ++i)
        {
            int from = path[i];
            int to = path[i + 1];

            // 删除正向边
            ArcNode *current = graph.vertexList[from].firstedge;
            ArcNode *prevNode = nullptr;
            while (current)
            {
                if (current->adjvex == to)
                {
                    if (prevNode)
                    {
                        prevNode->next = current->next;
                    }
                    else
                    {
                        graph.vertexList[from].firstedge = current->next;
                    }
                    ArcNode *temp = current;
                    current = current->next; // 先移动指针
                    delete temp;             // 再删除节点
                    graph.edgeCount--;
                    break;
                }
                prevNode = current;
                current = current->next;
            }

            // 删除反向边
            current = graph.vertexList[to].firstedge;
            prevNode = nullptr;
            while (current)
            {
                if (current->adjvex == from)
                {
                    if (prevNode)
                    {
                        prevNode->next = current->next;
                    }
                    else
                    {
                        graph.vertexList[to].firstedge = current->next;
                    }
                    ArcNode *temp = current;
                    current = current->next; // 先移动指针
                    delete temp;             // 再删除节点
                    break;
                }
                prevNode = current;
                current = current->next;
            }
        }
    }

    cout << "两点间的所有可达路径已删除！" << endl;
    graphManager.saveGraphToFile(graphManager.currentIndex);
}

// 查找所有可达路径
vector<vector<int>> Admin::findAllPaths(Graph &graph, int startIdx, int endIdx)
{
    vector<vector<int>> paths;
    vector<int> currentPath;
    bool visited[MAX_VERTEX_NUM] = {false};
    findPathsUtil(graph, startIdx, endIdx, visited, currentPath, paths);
    return paths;
}

// 辅助递归函数，用于查找所有路径
void Admin::findPathsUtil(Graph &graph, int currentIdx, int endIdx, bool visited[], vector<int> &currentPath, vector<vector<int>> &paths)
{//递归出口
    if (currentIdx < 0 || currentIdx >= MAX_VERTEX_NUM || visited[currentIdx])
    {
        return;
    }

    visited[currentIdx] = true;//当前路径标记
    currentPath.push_back(currentIdx);

    if (currentIdx == endIdx)
    {
        paths.push_back(currentPath);//其中一条路径 加入path
    }
    else
    {
        ArcNode *current = graph.vertexList[currentIdx].firstedge;
        while (current)
        {
            int adjvex = current->adjvex;
            if (!visited[adjvex])
            {
                findPathsUtil(graph, adjvex, endIdx, visited, currentPath, paths);
            }
            current = current->next;
        }
    }

    currentPath.pop_back();
    visited[currentIdx] = false;//当前路径取消标记
}
void Admin::exportUserInfo(AuthManager &auth)
{
    auth.saveUsersToFile();
}
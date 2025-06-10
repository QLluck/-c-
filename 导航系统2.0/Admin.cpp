#include "Admin.h"
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "dataManager.h"
void Admin::adminMenu(AuthManager& auth, GraphManager& graphManager) {
    int choice;
    do {
        cout << "\n====== ����Ա�˵� ======\n";
        cout << "1. �û�����\n";
        cout << "2. ��ͼ����\n";
        cout << "3. ��ǰ��ͼ�������\n";
        cout << "4. ��ǰ��ͼ�߹���\n";
        cout << "0. �������˵�\n";
        cout << "��ѡ�������";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "\n=== �û����� ===\n";
            cout << "1. ɾ���û�\n";
            cout << "2. �޸��û�����\n";
            cout<<  "3.�����û���Ϣ\n";
            cout << "0. ����\n";
            cin >> choice;
            if (choice == 1) deleteUser(auth);
            else if (choice == 2) modifyUser(auth);
            else if (choice == 3) exportUserInfo(auth);
            break;
        case 2:
            cout << "\n=== ��ͼ���� ===\n";
            cout << "1. �����ͼ�ļ�\n";
            cout << "2. �����µ�ͼ\n";
            cout << "3. ɾ���ѵ����ͼ\n";
            cout << "4. �л���ͼ\n";
            cout << "0. ����\n";
            cin >> choice;
            cin.ignore(); // ������뻺����
            if (choice == 1) {
                string filename;
                cout << "�����ͼ�ļ�����������չ������";
                getline(cin, filename);
                if (graphManager.importGraph(filename)) {
                    cout << "��ͼ����ɹ���" << endl;
                }
                else {
                    cout << "��ͼ����ʧ�ܣ������ļ����͸�ʽ��" << endl;
                }
                
            }
            else if (choice == 2) {              
                if (createNewMap(graphManager)) {
                    cout << "��ͼ�����ɹ����ѳɹ����룡" << endl;
                }
                else {
                    cout << "��ͼ����ʧ�ܻ���ʧ�ܣ�" << endl;
                }
            }
            else if (choice == 3) {
                deleteMap(graphManager);
            }
            else if (choice == 4) {
                graphManager.displayAvailableGraphs();
                int idx;
                cout << "ѡ���ͼ������";
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
//ɾ���ɸ�
void Admin::deleteUser(AuthManager& auth) {
    // ԭ���߼�����
    string username;
    cout << "����??�����������";
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
        cout << "�û���ɾ����\n";
        else
            cout << "ɾ��ʧ��:���ݿ����\n";
        return;
        // }
    }
}
    cout << "�û������ڻ���ɾ������Ա��\n";
}
//�޸� �ɸ�
void Admin::modifyUser(AuthManager& auth) {
    // ԭ���߼�����
    string username;
    cout << "����?�??��������";
    cin >> username;
    DataManager & db = DataManager::getInstance();
    User user; 
    //   for (auto& user : auth.users) {
    if(db.queryUser(username, &user)) 
    {

    if ( !user.isAdmin)
    {
        string newPassword = auth.getHiddenInput("�����룺");
        string passwordHash = auth.hashPassword(newPassword);
        string password = "password";
        if (db.updateUser(username, password, passwordHash))
            // auth.saveUsersToFile();
      
            cout << "�����Ѹ��£�\n";
        else
            cout << "����ʧ��\n";
        return;
        //    }
    }
}
    cout << "�û������ڻ����޸Ĺ���Ա��\n";
}
//���� �ɸ�
bool Admin::createNewMap(GraphManager& graphManager) {
    string mapName;
    cout << "�������?���?�";
    getline(cin, mapName);
    string filename = mapName + ".txt";
    ofstream file(filename);
    if (!file) return false;

    int vertexCount, edgeCount;
    cout << "���?������";
    cin >> vertexCount;
    cout << "���������";
    cin >> edgeCount;
    file << vertexCount << "\n" << edgeCount << "\n";

    cout << "����" << vertexCount << "���������ƣ�\n";
    for (int i = 0; i < vertexCount; i++) {
        string vertex;
        cin >> vertex;
        file << vertex << "\n";
    }

    cout << "����" << edgeCount << "������Ϣ����� �յ� ���룩��\n";
    for (int i = 0; i < edgeCount; i++) {
        string start, end;
        int weight;
        cin >> start >> end >> weight;
        file << start << " " << end << " " << weight << "\n";
    }

    file.close();
    return graphManager.importGraph(filename);
}
//ɾ�� �ɸ�
bool Admin::deleteMap(GraphManager& graphManager) {
    graphManager.displayAvailableGraphs();
    int idx;
    cout << "?��??���?�?������";
    cin >> idx;
    if (idx < 1 || idx > graphManager.getGraphCount()) return false;

    graphManager.graphs[idx - 1].graph.clear();
    for (int i = idx - 1; i < graphManager.graphCount - 1; i++) {
        graphManager.graphs[i] = graphManager.graphs[i + 1];
    }
    graphManager.graphCount--;
    return true;
}
//ͼ�Ķ������
void Admin::manageMapVertices(Graph& graph) {
    int choice;
    do {
        cout << "\n=== ������� ===\n";
        cout << "1. ���?���\n";
        cout << "2. ?������\n";
        cout << "3. �??�������\n";
        cout << "0. ����\n";
        cin >> choice;
        cin.ignore();

        string name;
        int index;
        switch (choice) {
        case 1:
            cout << "������������?�";
            getline(cin, name);
            if (graph.getVertexIndex(name) == -1) {
                graph.vertexList[graph.vertexCount].data = name;
                graph.vertexCount++;
            }
            break;
        case 2:
            cout << "����??���?������?�";
            getline(cin, name);
            index = graph.getVertexIndex(name);
            if (index != -1) {
                // ����������ر�
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
                // �ƶ���������
                for (int i = index; i < graph.vertexCount - 1; i++) {
                    graph.vertexList[i] = graph.vertexList[i + 1];
                    // �����ڽӱ��еĶ�������
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
//�߹���
void Admin::manageMapEdges(Graph& graph) {
    int choice;
    do {
        cout << "\n=== �߹��� ===\n";
        cout << "1. ���ӱ�\n";
        cout << "2. ɾ���ߣ�ָ������ԣ�\n";
        cout << "3. �޸ı�Ȩֵ\n";
        cout << "4. ɾ�����·�����б�\n";
        cout << "0. ����\n";
        cin >> choice;
        cin.ignore();

        string start, end;
        int startIdx, endIdx;
        switch (choice) {
        case 4:
            cout << "������㣺";
            getline(cin, start);
            cout << "�����??";
            getline(cin, end);
            startIdx = graph.getVertexIndex(start);
            endIdx = graph.getVertexIndex(end);
            if (startIdx == -1 || endIdx == -1) {
                cout << "���㲻���ڣ�\n";
                break;
            }
            // �������·����ɾ����
            int path[MAX_VERTEX_NUM], count = 0;
            // �򻯵�·����ȡ�߼��������ʵ��Dijkstraʵ�ֵ�����
            // ɾ��·���ϵ����б�
            break;
        }
    } while (choice != 0);
}
 void Admin::exportUserInfo(AuthManager&auth)
 {
     auth.saveUsersToFile();
 }
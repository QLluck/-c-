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
        
        cout << "\n====== ����Ա�˵� ======\n";
        cout << "1. �û�����\n";
        cout << "2. ��ͼ����\n";
        cout << "3. ��ǰ��ͼ�������\n";
        cout << "4. ��ǰ��ͼ�߹���\n";
        cout << "0. �˳���¼\n";
        cout << "��ѡ�������";
        cin >> choice;
        cin.ignore();
        system("cls");

        int choose;
        switch (choice)
        {
        case 1:
            cout << "\n=== �û����� ===\n";
            cout << "1. ɾ���û�\n";
            cout << "2. �޸��û�����\n";
            cout << "3.�����û���Ϣ\n";
            cout << "0. ����\n";

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
                cout << "\n=== ��ͼ���� ===\n";
                cout << "1. �����ͼ�ļ�\n";
                cout << "2. �����µ�ͼ\n";
                cout << "3. ɾ���ѵ����ͼ\n";
                cout << "4. �л���ͼ\n";
                cout << "5.�鿴��ǰ��ͼ��Ϣ\n";
                cout << "0. ����\n";
                cin >> choose;
                cin.ignore(); // ������뻺����
                if (choose == 1)
                {
                    string filename;
                    cout << "�����ͼ�ļ�����������չ������";

                    cin >> filename;
                    cin.ignore();
                    if (graphManager.importGraph(filename))
                    {
                        cout << "��ͼ����ɹ���" << endl;
                    }
                    else
                    {
                        cout << "��ͼ����ʧ�ܣ������ļ����͸�ʽ��" << endl;
                    }
                }
                else if (choose == 2)
                {
                    if (createNewMap(graphManager))
                    {
                        cout << "��ͼ�����ɹ����ѳɹ����룡" << endl;
                    }
                    else
                    {
                        cout << "��ͼ����ʧ�ܻ���ʧ�ܣ�" << endl;
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
                    cout << "ѡ���ͼ������";
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
    // ԭ���߼�����
    string username;
    cout << "����Ҫɾ�����û�����";
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
                cout << "�û���ɾ����\n";
            else
                cout << "ɾ��ʧ��:���ݿ����\n";
            return;
            // }
        }
    }
    cout << "�û������ڻ���ɾ������Ա��\n";
}

void Admin::modifyUser(AuthManager &auth)
{
    // ԭ���߼�����
    string username;
    cout << "����Ҫ�޸ĵ��û�����";
    cin >> username;
    DataManager &db = DataManager::getInstance();
    User user;
    //   for (auto& user : auth.users) {
    if (db.queryUser(username, &user))
    {

        if (!user.isAdmin)
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

bool Admin::createNewMap(GraphManager &graphManager)
{
    string mapName;
    cout << "�����µ�ͼ���ƣ�";
    getline(cin, mapName);
    string filename = mapName + ".txt";
    ofstream file(filename);
    if (!file)
        return false;

    int vertexCount, edgeCount;
    cout << "���붥������";
    cin >> vertexCount;
    cout << "���������";
    cin >> edgeCount;
    file << vertexCount << "\n"
         << edgeCount << "\n";

    cout << "����" << vertexCount << "���������ƣ�\n";
    string *vList = new string[vertexCount]; // ��ʱ�洢������������
    for (int i = 0; i < vertexCount; i++)
    {
        string vertex;
        cin >> vertex;
        // ����
        vList[i] = vertex;
        for (int j = 0; j < i; j++)
        {
            if (vList[j] == vertex)
            {
                cout << "���������ظ������������룺";
                i--;
                continue;
            }
        }
        file << vertex << "\n";
    }
    delete[] vList;

    cout << "����" << edgeCount << "������Ϣ����� �յ� ���룩��\n";
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
    cout << "ѡ��Ҫɾ���ĵ�ͼ������";
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
        cout << "\n=== ������� ===\n";
        cout << "1. ��Ӷ���\n";
        cout << "2. ɾ������\n";
        cout << "3. �޸Ķ�������\n";
        cout << "0. ����\n";
        cin >> choice;
        cin.ignore();

        string name;
        int index;
        switch (choice)
        {
        case 1:
            cout << "�����¶������ƣ�";
            getline(cin, name);
            if (graph.getVertexIndex(name) == -1)
            {
                graph.vertexList[graph.vertexCount].data = name;
                graph.vertexCount++;
                // ���浽�ļ�
                graphManager.saveGraphToFile(graphManager.currentIndex);
                cout << "������ӳɹ���" << endl;
            }
            break;
        case 2:
            cout << "����Ҫɾ���Ķ������ƣ�";
            getline(cin, name);
            index = graph.getVertexIndex(name);
            if (index != -1)
            {
                // ����������ر�==
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
                // ���������ڽӱ��еĶ�������
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

                // �ƶ���������
                for (int i = index; i < graph.vertexCount - 1; i++)
                {
                    graph.vertexList[i] = graph.vertexList[i + 1];
                }
                graph.vertexCount--;
                // ���浽�ļ�
                graphManager.saveGraphToFile(graphManager.currentIndex);
                cout << "����ɾ���ɹ���" << endl;
            }
            break;
        case 3:
            cout << "����Ҫ�޸ĵĶ������ƣ�";
            getline(cin, name);
            index = graph.getVertexIndex(name);
            if (index != -1)
            {
                string newName;
                cout << "�����µĶ������ƣ�";
                getline(cin, newName);
                graph.vertexList[index].data = newName; // ���������ƣ������޸ı�
                cout << "�����������޸ģ�" << endl;
                // ���浽�ļ�
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
        cout << "\n=== �߹��� ===\n";
        cout << "1. ��ӱ�\n";
        cout << "2. ɾ���ߣ�ָ������ԣ�\n";
        cout << "3. �޸ı�Ȩֵ\n";
        cout << "4. ɾ����������·�����б�\n";
        cout << "5.ɾ����������пɴ�·��\n";
        cout << "0. ����\n";
        cin >> choice;
        cin.ignore();

        string start, end;
        int startIdx, endIdx, weight;
        switch (choice)
        {
        case 1:
        {
            cout << "����������ƣ�";
            getline(cin, start);
            cout << "�����յ����ƣ�";
            getline(cin, end);
            cout << "������룺";
            cin >> weight;
            cin.ignore();

            startIdx = graph.getVertexIndex(start);
            endIdx = graph.getVertexIndex(end);

            if (startIdx == -1 || endIdx == -1)
            {
                cout << "���㲻���ڣ�" << endl;
                break;
            }

            // ����Ƿ��Ѿ����ڸñ�
            ArcNode *current = graph.vertexList[startIdx].firstedge;
            while (current)
            {
                if (current->adjvex == endIdx)
                {
                    cout << "���Ѵ��ڣ�" << endl;
                    break;
                }
                current = current->next;
            }

            if (!current)
            {
                // �����µı߽ڵ�
                ArcNode *newArc = new ArcNode;
                newArc->adjvex = endIdx;
                newArc->weight = weight;
                newArc->next = graph.vertexList[startIdx].firstedge;
                newArc->visited = false;
                graph.vertexList[startIdx].firstedge = newArc;

                // ��ӷ���ߣ�����ͼ��
                ArcNode *reverseArc = new ArcNode;
                reverseArc->adjvex = startIdx;
                reverseArc->weight = weight;

                reverseArc->next = graph.vertexList[endIdx].firstedge;

                reverseArc->visited = false;
                graph.vertexList[endIdx].firstedge = reverseArc;

                graph.edgeCount++;
                cout << "������ӣ�" << endl;
                graphManager.saveGraphToFile(graphManager.currentIndex);
            }
            break;
        }

        case 2:
        {
            cout << "����������ƣ�";
            getline(cin, start);
            cout << "�����յ����ƣ�";
            getline(cin, end);

            startIdx = graph.getVertexIndex(start);
            endIdx = graph.getVertexIndex(end);

            if (startIdx == -1 || endIdx == -1)
            {
                cout << "���㲻���ڣ�" << endl;
                break;
            }

            // ɾ�������
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

            // ɾ�������
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

            cout << "����ɾ����" << endl;
            graphManager.saveGraphToFile(graphManager.currentIndex);
            break;
        }

        case 3:
        {
            cout << "����������ƣ�";
            getline(cin, start);
            cout << "�����յ����ƣ�";
            getline(cin, end);
            cout << "�����µľ��룺";
            cin >> weight;
            cin.ignore();

            startIdx = graph.getVertexIndex(start);
            endIdx = graph.getVertexIndex(end);

            if (startIdx == -1 || endIdx == -1)
            {
                cout << "���㲻���ڣ�" << endl;
                break;
            }

            // �޸������Ȩֵ
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

            // �޸ķ����Ȩֵ
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

            cout << "��Ȩֵ���޸ģ�" << endl;
            graphManager.saveGraphToFile(graphManager.currentIndex);
            break;
        }

        case 4:
        {
            cout << "������㣺";
            getline(cin, start);
            cout << "�����յ㣺";
            getline(cin, end);
            startIdx = graph.getVertexIndex(start);
            endIdx = graph.getVertexIndex(end);
            if (startIdx == -1 || endIdx == -1)
            {
                cout << "���㲻���ڣ�" << endl;
                break;
            }

            // �������·��
            int path[MAX_VERTEX_NUM];
            int count = 0;
            bool found = false;

            // ʹ�� Dijkstra �㷨�ҵ����·��
            const int INF = 99999;    // �����
            int dist[MAX_VERTEX_NUM]; // �������·���ľ���
            bool s[MAX_VERTEX_NUM];   // ����Ƿ��ҵ����·��
            int prev[MAX_VERTEX_NUM]; // ����·��ǰ���ڵ�

            // ��ʼ��
            for (int i = 0; i < graph.vertexCount; ++i)
            {
                dist[i] = INF;
                s[i] = false;
                prev[i] = -1;
            }

            dist[startIdx] = 0;

            // Dijkstra�㷨��ѭ��
            for (int i = 0; i < graph.vertexCount; ++i)
            {
                int u = -1;
                int minDist = INF;

                // �ҳ���ǰδȷ������̾���Ķ���
                for (int j = 0; j < graph.vertexCount; ++j)
                {
                    if (!s[j] && dist[j] < minDist)
                    {
                        u = j;
                        minDist = dist[j];
                    }
                }

                if (u == -1 || u == endIdx)
                    break; // �Ҳ���·�����ҵ��յ�

                s[u] = true;

                // �������ڶ���ľ���
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

            // ����·��
            if (dist[endIdx] == INF)
            {
                cout << "û��·���ɴ" << endl;
                break;
            }

            // ����·��
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
                    cout << "·������������Χ��" << endl;
                    break;
                }
            }

            // ��ת·��
            reverse(path, path + count);

            // ɾ��·���ϵ����б�
            for (int i = 0; i < count - 1; ++i)
            {
                int from = path[i];
                int to = path[i + 1];

                // ɾ�������
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

                // ɾ�������
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

            cout << "���·���ϵ����б���ɾ����" << endl;
            // ���浽�ļ�
            graphManager.saveGraphToFile(graphManager.currentIndex);
            break;
        }

        case 5:
        {
            cout << "����������ƣ�";
            getline(cin, start);
            cout << "�����յ����ƣ�";
            getline(cin, end);
            startIdx = graph.getVertexIndex(start);
            endIdx = graph.getVertexIndex(end);
            if (startIdx == -1 || endIdx == -1)
            {
                cout << "���㲻���ڣ�" << endl;
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

// ɾ�����������пɴ�·��
void Admin::deleteAllPathsBetween(Graph &graph, int startIdx, int endIdx, GraphManager &graphManager) 
{
    vector<vector<int>> paths = findAllPaths(graph, startIdx, endIdx);

    if (paths.empty())
    {
        cout << "�����û�пɴ�·����" << endl;
        return;
    }

    for (const auto &path : paths)
    {
        for (size_t i = 0; i < path.size() - 1; ++i)
        {
            int from = path[i];
            int to = path[i + 1];

            // ɾ�������
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
                    current = current->next; // ���ƶ�ָ��
                    delete temp;             // ��ɾ���ڵ�
                    graph.edgeCount--;
                    break;
                }
                prevNode = current;
                current = current->next;
            }

            // ɾ�������
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
                    current = current->next; // ���ƶ�ָ��
                    delete temp;             // ��ɾ���ڵ�
                    break;
                }
                prevNode = current;
                current = current->next;
            }
        }
    }

    cout << "���������пɴ�·����ɾ����" << endl;
    graphManager.saveGraphToFile(graphManager.currentIndex);
}

// �������пɴ�·��
vector<vector<int>> Admin::findAllPaths(Graph &graph, int startIdx, int endIdx)
{
    vector<vector<int>> paths;
    vector<int> currentPath;
    bool visited[MAX_VERTEX_NUM] = {false};
    findPathsUtil(graph, startIdx, endIdx, visited, currentPath, paths);
    return paths;
}

// �����ݹ麯�������ڲ�������·��
void Admin::findPathsUtil(Graph &graph, int currentIdx, int endIdx, bool visited[], vector<int> &currentPath, vector<vector<int>> &paths)
{//�ݹ����
    if (currentIdx < 0 || currentIdx >= MAX_VERTEX_NUM || visited[currentIdx])
    {
        return;
    }

    visited[currentIdx] = true;//��ǰ·�����
    currentPath.push_back(currentIdx);

    if (currentIdx == endIdx)
    {
        paths.push_back(currentPath);//����һ��·�� ����path
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
    visited[currentIdx] = false;//��ǰ·��ȡ�����
}
void Admin::exportUserInfo(AuthManager &auth)
{
    auth.saveUsersToFile();
}
#include "Queue.h"
#include "Graph.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// ���캯��
Graph::Graph() : vertexCount(0), edgeCount(0) {
    for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
        vertexList[i].firstedge = nullptr; // ��ʼ��firstedge
        visited[i] = false;
    }
}

// ��������
Graph::~Graph() {
    for (int i = 0; i < vertexCount; ++i) {
        ArcNode* current = vertexList[i].firstedge;
        while (current) {
            ArcNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

// ���ļ�����ͼ
bool Graph::createGraph(ifstream& file) {
    // �������ͼ
    for (int i = 0; i < vertexCount; ++i) {
        ArcNode* current = vertexList[i].firstedge;
        while (current) {
            ArcNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
    vertexCount = 0;
    edgeCount = 0;

    // ��ȡ�������ͱ���
    if (!(file >> vertexCount >> edgeCount)) {
        return false;
    }

    if (vertexCount == 0 || edgeCount == 0) {
        return false;
    }

    // ��ȡ������Ϣ
    for (int i = 0; i < vertexCount; ++i) {
        string vertexName;
        if (!(file >> vertexName)) {
            return false;
        }
        vertexList[i].data = vertexName;
        vertexList[i].firstedge = nullptr;
    }

    // ��ȡ����Ϣ�������ڽӱ�
    for (int i = 0; i < edgeCount; ++i) {
        string startVertex, endVertex;
        int weight;
        if (!(file >> startVertex >> endVertex >> weight)) {
            return false;
        }

        int startIdx = getVertexIndex(startVertex);
        int endIdx = getVertexIndex(endVertex);

        if (startIdx == -1 || endIdx == -1) {
            return false;
        }

        // �����µı߽ڵ�
        ArcNode* newArc = new ArcNode;
        newArc->adjvex = endIdx;
        newArc->weight = weight;
        newArc->next = vertexList[startIdx].firstedge;
        newArc->visited = false;
        vertexList[startIdx].firstedge = newArc;

        // ����������ͼ����Ҫ��ӷ����
        ArcNode* reverseArc = new ArcNode;
        reverseArc->adjvex = startIdx;
        reverseArc->weight = weight;
        reverseArc->next = vertexList[endIdx].firstedge;
        reverseArc->visited = false;
        vertexList[endIdx].firstedge = reverseArc;
    }

    return true;
}

// ��ʾͼ����Ϣ
void Graph::displayGraphInfo() const {
    if (vertexCount == 0) {
        cout << "ͼΪ�գ�" << endl;
        return;
    }

    cout << "��ͼ�ĵص���Ϣ��" << endl;
    for (int i = 0; i < vertexCount; ++i) {
        if (i >= 0 && i < vertexCount) {
            cout << (i + 1) << ". " << vertexList[i].data << endl;
        }
        else {
            cout << "��������������Χ��" << endl;
        }
    }

    cout << "\n��ͼ��·����Ϣ��" << endl;
    for (int i = 0; i < vertexCount; ++i) {
        if (i >= 0 && i < vertexCount) {
            ArcNode* currentArc = vertexList[i].firstedge;
            while (currentArc != nullptr) { // ��� currentArc �Ƿ�Ϊ nullptr
                int adjvex = currentArc->adjvex;
                if (adjvex >= 0 && adjvex < vertexCount) {
                    cout << vertexList[i].data << " -> " << vertexList[adjvex].data
                        << " (����: " << currentArc->weight << ")" << endl;
                }
                else {
                    cout << "�ߵ�Ŀ�궥������������Χ��" << endl;
                }
                currentArc = currentArc->next;
            }
        }
        else {
            cout << "��������������Χ��" << endl;
        }
    }
}

// ������ȱ���
void Graph::DFS(int v) {
    // ���� visited ����
    for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
        visited[i] = false;
    }

    if (v < 0 || v >= vertexCount) {
        cout << "��Ч�Ķ���������" << endl;
        return;
    }

    Stack<int> stack;
    stack.push(v);

    // ��Ƿ���
    if (v >= 0 && v < vertexCount) {
        visited[v] = true;
        cout << vertexList[v].data << " ";
    }
    else {
        cout << "��������������Χ��" << endl;
        return;
    }

    while (!stack.isEmpty()) {
        int u = stack.peek();
        if (u < 0 || u >= vertexCount) {
            stack.pop();
            continue;
        }

        ArcNode* currentArc = vertexList[u].firstedge;
        int adjacentVertex = -1;

        while (currentArc) {
            int w = currentArc->adjvex;
            if (w >= 0 && w < vertexCount && !visited[w]) {
                adjacentVertex = w;
                break;
            }
            currentArc = currentArc->next;
        }

        if (adjacentVertex != -1) {
            if (adjacentVertex >= 0 && adjacentVertex < vertexCount) {
                visited[adjacentVertex] = true;
                cout << vertexList[adjacentVertex].data << " ";
                stack.push(adjacentVertex);
            }
            else {
                cout << "�ڽӶ�������������Χ��" << endl;
            }
        }
        else {
            stack.pop();
        }
    }
    cout << endl;
}

//������ȱ���
void Graph::BFS(int v) {
    // ���� visited ����
    for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
        visited[i] = false;
    }

    if (v < 0 || v >= vertexCount) {
        cout << "��Ч�Ķ���������" << endl;
        return;
    }

    Queue queue;
    BFSNode startNode = { v, 0 }; // ���� BFSNode ����
    queue.enqueue(startNode); // ��� BFSNode ����

    // ��Ƿ���
    if (v >= 0 && v < vertexCount) {
        visited[v] = true;
        cout << vertexList[v].data << " ";
    }
    else {
        cout << "��������������Χ��" << endl;
        return;
    }

    while (!queue.isEmpty()) {
        BFSNode currentNode = queue.dequeue(); // ��ȡ BFSNode ����
        int u = currentNode.index; // ��ȡ��������

        ArcNode* currentArc = vertexList[u].firstedge;
        while (currentArc) {
            int w = currentArc->adjvex;
            if (w >= 0 && w < vertexCount && !visited[w]) {
                visited[w] = true;
                cout << vertexList[w].data << " ";
                BFSNode nextNode = { w, currentNode.distance + 1 }; // ������һ�� BFSNode
                queue.enqueue(nextNode); // �����һ�� BFSNode ����
            }
            currentArc = currentArc->next;
        }
    }
    cout << endl;
}

// �������·����Dijkstra�㷨��
void Graph::findShortestPath(int startIdx, int endIdx) {
    if (startIdx < 0 || startIdx >= vertexCount ||
        endIdx < 0 || endIdx >= vertexCount) {
        cout << "��Ч�Ķ���������" << endl;
        return;
    }

    const int INF = 99999; // �����
    int dist[MAX_VERTEX_NUM];  // �������·���ľ���
    bool s[MAX_VERTEX_NUM];    // ����Ƿ��ҵ����·��
    int path[MAX_VERTEX_NUM];  // ����·��ǰ���ڵ�

    // ��ʼ��
    for (int i = 0; i < vertexCount; ++i) {
        dist[i] = INF;
        s[i] = false;
        path[i] = -1;
    }

    dist[startIdx] = 0;

    // Dijkstra�㷨��ѭ��
    for (int i = 0; i < vertexCount; ++i) {
        int u = -1;
        int minDist = INF;

        // �ҳ���ǰδȷ������̾���Ķ���
        for (int j = 0; j < vertexCount; ++j) {
            if (!s[j] && dist[j] < minDist) {
                u = j;
                minDist = dist[j];
            }
        }

        if (u == -1 || u == endIdx) break; // �Ҳ���·�����ҵ��յ�

        s[u] = true;

        // �������ڶ���ľ���
        ArcNode* currentArc = vertexList[u].firstedge;
        while (currentArc) {
            int v = currentArc->adjvex;
            if (v >= 0 && v < vertexCount && !s[v] && dist[u] + currentArc->weight < dist[v]) {
                dist[v] = dist[u] + currentArc->weight;
                path[v] = u;
            }
            currentArc = currentArc->next;
        }
    }

    // ������·��
    cout << "�� " << vertexList[startIdx].data
        << " �� " << vertexList[endIdx].data
        << " ����̾���Ϊ��" << dist[endIdx] << endl;

    // ����·��
    if (dist[endIdx] == INF) {
        cout << "û��·���ɴ" << endl;
        return;
    }

    // ����·��
    int pathNodes[MAX_VERTEX_NUM];
    int count = 0;
    int currentIndex = endIdx;
    while (currentIndex != -1) {
        if (currentIndex >= 0 && currentIndex < vertexCount) {
            pathNodes[count++] = currentIndex;
            currentIndex = path[currentIndex];
        }
        else {
            cout << "·������������Χ��" << endl;
            break;
        }
    }

    // ��ת·�������
    cout << "·����";
    for (int i = count - 1; i >= 0; --i) {
        cout << vertexList[pathNodes[i]].data;
        if (i != 0) cout << " -> ";
    }
    cout << endl;
}

// ��ȡ��������
int Graph::getVertexIndex(const string& vertexName) const {
    for (int i = 0; i < vertexCount; ++i) {
        if (vertexList[i].data == vertexName) {
            return i;
        }
    }
    return -1; // δ�ҵ�
}

// ��ȡ��������
string Graph::getVertexName(int index) const {
    if (index >= 0 && index < vertexCount) {
        return vertexList[index].data;
    }
    return "";
}

void Graph::clear() {
    for (int i = 0; i < vertexCount; ++i) {
        ArcNode* current = vertexList[i].firstedge;
        while (current) {
            ArcNode* temp = current;
            current = current->next;
            delete temp;
        }
        vertexList[i].firstedge = nullptr;
    }
    vertexCount = 0;
    edgeCount = 0;
    for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
        visited[i] = false;
    }
}

void Graph::searchNearbyLocations(const string& startName, int maxDistance) const {
    int startIdx = getVertexIndex(startName);
    if (startIdx == -1) {
        cout << "��㲻���ڣ�" << endl;
        return;
    }

    Queue queue;  // ʹ�÷�ģ�� Queue������ BFSNode ���ͣ�
    bool visited[MAX_VERTEX_NUM] = { false };

    queue.enqueue({ startIdx, 0 }); // ��ӳ�ʼ�ڵ�
    visited[startIdx] = true;

    cout << "�ܱߵص㣨�����" << maxDistance << "�ף���" << endl;
    while (!queue.isEmpty()) {
        BFSNode current = queue.dequeue();
        cout << vertexList[current.index].data << " (" << current.distance << "��)" << endl;

        ArcNode* edge = vertexList[current.index].firstedge;
        while (edge) {
            if (!visited[edge->adjvex] && (current.distance + edge->weight) <= maxDistance) {
                visited[edge->adjvex] = true;
                queue.enqueue({ edge->adjvex, current.distance + edge->weight }); // ����½ڵ�
            }
            edge = edge->next;
        }
    }
}

// ͼ�����๹�캯��
GraphManager::GraphManager() : graphCount(0), currentIndex(-1) {}

// ͼ��������������
GraphManager::~GraphManager() {
    for (int i = 0; i < graphCount; ++i) {
        graphs[i].graph.~Graph();
    }
}

// �����ͼ����
bool GraphManager::importGraph(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        return false;
    }

    if (graphCount >= 10) {
        file.close();
        return false;
    }

    // ��ȡ��ͼ���ƣ������ļ�����Ϊ��ͼ���ƣ�ȥ����չ����
    size_t dotPos = fileName.find_last_of('.');
    string graphName = fileName.substr(0, dotPos);

    // ����Ƿ��Ѵ���ͬ����ͼ
    for (int i = 0; i < graphCount; ++i) {
        if (graphs[i].name == graphName) {
            file.close();
            return false;
        }
    }

    // �������ͼ���ݲ�������ͼ
    graphs[graphCount].graph.clear();
    if (!graphs[graphCount].graph.createGraph(file)) {
        file.close();
        return false;
    }

    //��ӵ�ͼ�б�
    graphs[graphCount].name = graphName;
    graphCount++;

    // ����ǵ�һ������ĵ�ͼ������Ϊ��ǰ��ͼ
    if (currentIndex == -1) {
        currentIndex = 0;
    }

    file.close();
    return true;
}

// ��ʾ��ǰ��ͼ��Ϣ
bool GraphManager::displayCurrentGraphInfo() const {
    if (currentIndex == -1 || currentIndex >= graphCount) {
        cout << "û�п��õ�ͼ��" << endl;
        return false;
    }

    cout << "��ǰ��ͼ�� " << graphs[currentIndex].name << endl;
    graphs[currentIndex].graph.displayGraphInfo();
    return true;
}

// ������ȱ���
bool GraphManager::depthFirstTraversal() {
    if (currentIndex == -1 || currentIndex >= graphCount) {
        cout << "û�п��õ�ͼ��" << endl;
        return false;
    }

    cout << "������ȱ��������";
    graphs[currentIndex].graph.DFS(0); // �ӵ�һ�����㿪ʼ
    return true;
}

// ������ȱ���
bool GraphManager::breadthFirstTraversal() {
    if (currentIndex == -1 || currentIndex >= graphCount) {
        cout << "û�п��õ�ͼ��" << endl;
        return false;
    }

    cout << "������ȱ��������";
    graphs[currentIndex].graph.BFS(0); // �ӵ�һ�����㿪ʼ
    return true;
}

// �������·��
bool GraphManager::findShortestPath(const string& start, const string& end) {
    if (currentIndex == -1 || currentIndex >= graphCount) {
        cout << "û�п��õ�ͼ��" << endl;
        return false;
    }

    Graph& currentGraph = graphs[currentIndex].graph;
    int startIdx = currentGraph.getVertexIndex(start);
    int endIdx = currentGraph.getVertexIndex(end);

    if (startIdx == -1 || endIdx == -1) {
        cout << "�����յ㲻���ڣ�" << endl;
        return false;
    }

    currentGraph.findShortestPath(startIdx, endIdx);
    return true;
}

// ��ʾ���õ�ͼ
void GraphManager::displayAvailableGraphs() const {
    if (graphCount == 0) {
        cout << "û�п��õ�ͼ��" << endl;
        return;
    }

    cout << "���õ�ͼ�б�" << endl;
    for (int i = 0; i < graphCount; ++i) {
        cout << (i + 1) << ". " << graphs[i].name << endl;
    }
}

// �л���ͼ
bool GraphManager::switchGraph(int index) {
    if (index < 1 || index > graphCount) {
        return false;
    }

    currentIndex = index - 1;
    return true;
}

// ��ȡ��ǰ��ͼ����
string GraphManager::getCurrentGraphName() const {
    if (currentIndex != -1 && currentIndex < graphCount) {
        return graphs[currentIndex].name;
    }
    return "";
}

// ��ȡ��ͼ����
int GraphManager::getGraphCount() const {
    return graphCount;
}

// ����Ƿ��п��õ�ͼ
bool GraphManager::isGraphAvailable() const {
    return currentIndex != -1 && currentIndex < graphCount;
}
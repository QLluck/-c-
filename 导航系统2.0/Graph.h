#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include<vector>
using namespace std;

const int MAX_VERTEX_NUM = 100; // ��󶥵���

// �߱�ڵ�
class ArcNode {
public:
    int adjvex;                 // �ñ���ָ��Ķ����λ��
    int weight;                 // �ߵ�Ȩֵ
    ArcNode* next;              // ָ����һ���ߵ�ָ��
    bool visited;               // ��Ǹñ��Ƿ񱻷��ʹ�
};

// �����ڵ�
class VertexNode {
public:
    string data;                // ������Ϣ
    ArcNode* firstedge;         // ָ���һ�������ö���ı�
};

class BFSNode {//���ڹ�����������Ķ���Ԫ��
public:
    int index;//��ǰ��������
    int distance;//�ۼƾ��루����㵽��ǰ���㣩
};

// ͼ��
class Graph {
public:
    Graph();
    ~Graph();
    bool createGraph(ifstream& file); // ���ļ�����ͼ
    void displayGraphInfo() const;    // ��ʾͼ����Ϣ
    void DFS(int v); // ������ȱ���
    void BFS(int v); // ������ȱ���
    void findShortestPath(int startIdx, int endIdx); // �������·��
    int getVertexIndex(const string& vertexName) const; // ��ȡ��������
    string getVertexName(int index) const;              // ��ȡ��������
    int getVertexCount() const { return vertexCount; }
    int getEdgeCount() const { return edgeCount; }
    bool isEmpty() const { return vertexCount == 0; }
    void clear();
    void searchNearbyLocations(const string& startName, int maxDistance) const;


public:
    VertexNode vertexList[MAX_VERTEX_NUM]; // �����
    int vertexCount;                       // ������
    int edgeCount;                         // ����
    bool visited[MAX_VERTEX_NUM];          // ���ʱ������
    int shortestDistance; // �������·���ľ���
};

// ͼ�����࣬���ڹ�����ͼ
class GraphManager {
public:
    GraphManager();
    ~GraphManager();
    bool importGraph(const string& fileName); // �����ͼ����
    bool displayCurrentGraphInfo() const;     // ��ʾ��ǰ��ͼ��Ϣ
    bool depthFirstTraversal();             //�������
    bool breadthFirstTraversal();          //�������
    bool findShortestPath(const string& start, const string& end); // �������·��
    void displayAvailableGraphs() const;      // ��ʾ���õ�ͼ
    bool switchGraph(int index);              // �л���ͼ
    string getCurrentGraphName() const;       // ��ȡ��ǰ��ͼ����
    bool isGraphAvailable() const;            // ����Ƿ��п��õ�ͼ
    bool saveGraphToFile(int index);  //��ͼ�����ļ�
    int getGraphCount() const;                // ��ȡ��ͼ����
    void displayMainMenu();//��¼����
    void displayNavigationMenu();//��������
    

public:
    struct GraphInfo {
        string name;
        Graph graph;
    };
    GraphInfo graphs[10]; // ���洢10����ͼ
    int graphCount;
    int currentIndex;
    int shortestDistance; // �������·���ľ���
};

#endif
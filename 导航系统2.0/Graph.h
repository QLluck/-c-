#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include<vector>
using namespace std;

const int MAX_VERTEX_NUM = 100; // 最大顶点数

// 边表节点
class ArcNode {
public:
    int adjvex;                 // 该边所指向的顶点的位置
    int weight;                 // 边的权值
    ArcNode* next;              // 指向下一条边的指针
    bool visited;               // 标记该边是否被访问过
};

// 顶点表节点
class VertexNode {
public:
    string data;                // 顶点信息
    ArcNode* firstedge;         // 指向第一条依附该顶点的边
};

class BFSNode {//用于广度优先搜索的队列元素
public:
    int index;//当前顶点索引
    int distance;//累计距离（从起点到当前顶点）
};

// 图类
class Graph {
public:
    Graph();
    ~Graph();
    bool createGraph(ifstream& file); // 从文件创建图
    void displayGraphInfo() const;    // 显示图的信息
    void DFS(int v); // 深度优先遍历
    void BFS(int v); // 广度优先遍历
    void findShortestPath(int startIdx, int endIdx); // 查找最短路径
    int getVertexIndex(const string& vertexName) const; // 获取顶点索引
    string getVertexName(int index) const;              // 获取顶点名称
    int getVertexCount() const { return vertexCount; }
    int getEdgeCount() const { return edgeCount; }
    bool isEmpty() const { return vertexCount == 0; }
    void clear();
    void searchNearbyLocations(const string& startName, int maxDistance) const;


public:
    VertexNode vertexList[MAX_VERTEX_NUM]; // 顶点表
    int vertexCount;                       // 顶点数
    int edgeCount;                         // 边数
    bool visited[MAX_VERTEX_NUM];          // 访问标记数组
    int shortestDistance; // 保存最短路径的距离
};

// 图管理类，用于管理多个图
class GraphManager {
public:
    GraphManager();
    ~GraphManager();
    bool importGraph(const string& fileName); // 导入地图数据
    bool displayCurrentGraphInfo() const;     // 显示当前地图信息
    bool depthFirstTraversal();             //广度优先
    bool breadthFirstTraversal();          //深度优先
    bool findShortestPath(const string& start, const string& end); // 查找最短路径
    void displayAvailableGraphs() const;      // 显示可用地图
    bool switchGraph(int index);              // 切换地图
    string getCurrentGraphName() const;       // 获取当前地图名称
    bool isGraphAvailable() const;            // 检查是否有可用地图
    bool saveGraphToFile(int index);  //将图存入文件
    int getGraphCount() const;                // 获取地图数量
    void displayMainMenu();//登录界面
    void displayNavigationMenu();//导航界面
    

public:
    struct GraphInfo {
        string name;
        Graph graph;
    };
    GraphInfo graphs[10]; // 最多存储10个地图
    int graphCount;
    int currentIndex;
    int shortestDistance; // 保存最短路径的距离
};

#endif
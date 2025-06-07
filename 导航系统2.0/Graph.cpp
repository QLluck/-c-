#include "Queue.h"
#include "Graph.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// 构造函数
Graph::Graph() : vertexCount(0), edgeCount(0) {
    for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
        vertexList[i].firstedge = nullptr; // 初始化firstedge
        visited[i] = false;
    }
}

// 析构函数
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

// 从文件创建图
bool Graph::createGraph(ifstream& file) {
    // 清空现有图
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

    // 读取顶点数和边数
    if (!(file >> vertexCount >> edgeCount)) {
        return false;
    }

    if (vertexCount == 0 || edgeCount == 0) {
        return false;
    }

    // 读取顶点信息
    for (int i = 0; i < vertexCount; ++i) {
        string vertexName;
        if (!(file >> vertexName)) {
            return false;
        }
        vertexList[i].data = vertexName;
        vertexList[i].firstedge = nullptr;
    }

    // 读取边信息并构建邻接表
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

        // 创建新的边节点
        ArcNode* newArc = new ArcNode;
        newArc->adjvex = endIdx;
        newArc->weight = weight;
        newArc->next = vertexList[startIdx].firstedge;
        newArc->visited = false;
        vertexList[startIdx].firstedge = newArc;

        // 由于是无向图，需要添加反向边
        ArcNode* reverseArc = new ArcNode;
        reverseArc->adjvex = startIdx;
        reverseArc->weight = weight;
        reverseArc->next = vertexList[endIdx].firstedge;
        reverseArc->visited = false;
        vertexList[endIdx].firstedge = reverseArc;
    }

    return true;
}

// 显示图的信息
void Graph::displayGraphInfo() const {
    if (vertexCount == 0) {
        cout << "图为空！" << endl;
        return;
    }

    cout << "地图的地点信息：" << endl;
    for (int i = 0; i < vertexCount; ++i) {
        if (i >= 0 && i < vertexCount) {
            cout << (i + 1) << ". " << vertexList[i].data << endl;
        }
        else {
            cout << "顶点索引超出范围！" << endl;
        }
    }

    cout << "\n地图的路径信息：" << endl;
    for (int i = 0; i < vertexCount; ++i) {
        if (i >= 0 && i < vertexCount) {
            ArcNode* currentArc = vertexList[i].firstedge;
            while (currentArc != nullptr) { // 检查 currentArc 是否为 nullptr
                int adjvex = currentArc->adjvex;
                if (adjvex >= 0 && adjvex < vertexCount) {
                    cout << vertexList[i].data << " -> " << vertexList[adjvex].data
                        << " (距离: " << currentArc->weight << ")" << endl;
                }
                else {
                    cout << "边的目标顶点索引超出范围！" << endl;
                }
                currentArc = currentArc->next;
            }
        }
        else {
            cout << "顶点索引超出范围！" << endl;
        }
    }
}

// 深度优先遍历
void Graph::DFS(int v) {
    // 重置 visited 数组
    for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
        visited[i] = false;
    }

    if (v < 0 || v >= vertexCount) {
        cout << "无效的顶点索引！" << endl;
        return;
    }

    Stack<int> stack;
    stack.push(v);

    // 标记访问
    if (v >= 0 && v < vertexCount) {
        visited[v] = true;
        cout << vertexList[v].data << " ";
    }
    else {
        cout << "顶点索引超出范围！" << endl;
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
                cout << "邻接顶点索引超出范围！" << endl;
            }
        }
        else {
            stack.pop();
        }
    }
    cout << endl;
}

//广度优先遍历
void Graph::BFS(int v) {
    // 重置 visited 数组
    for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
        visited[i] = false;
    }

    if (v < 0 || v >= vertexCount) {
        cout << "无效的顶点索引！" << endl;
        return;
    }

    Queue queue;
    BFSNode startNode = { v, 0 }; // 创建 BFSNode 对象
    queue.enqueue(startNode); // 入队 BFSNode 对象

    // 标记访问
    if (v >= 0 && v < vertexCount) {
        visited[v] = true;
        cout << vertexList[v].data << " ";
    }
    else {
        cout << "顶点索引超出范围！" << endl;
        return;
    }

    while (!queue.isEmpty()) {
        BFSNode currentNode = queue.dequeue(); // 获取 BFSNode 对象
        int u = currentNode.index; // 获取顶点索引

        ArcNode* currentArc = vertexList[u].firstedge;
        while (currentArc) {
            int w = currentArc->adjvex;
            if (w >= 0 && w < vertexCount && !visited[w]) {
                visited[w] = true;
                cout << vertexList[w].data << " ";
                BFSNode nextNode = { w, currentNode.distance + 1 }; // 创建下一个 BFSNode
                queue.enqueue(nextNode); // 入队下一个 BFSNode 对象
            }
            currentArc = currentArc->next;
        }
    }
    cout << endl;
}

// 查找最短路径（Dijkstra算法）
void Graph::findShortestPath(int startIdx, int endIdx) {
    if (startIdx < 0 || startIdx >= vertexCount ||
        endIdx < 0 || endIdx >= vertexCount) {
        cout << "无效的顶点索引！" << endl;
        return;
    }

    const int INF = 99999; // 无穷大
    int dist[MAX_VERTEX_NUM];  // 保存最短路径的距离
    bool s[MAX_VERTEX_NUM];    // 标记是否找到最短路径
    int path[MAX_VERTEX_NUM];  // 保存路径前驱节点

    // 初始化
    for (int i = 0; i < vertexCount; ++i) {
        dist[i] = INF;
        s[i] = false;
        path[i] = -1;
    }

    dist[startIdx] = 0;

    // Dijkstra算法主循环
    for (int i = 0; i < vertexCount; ++i) {
        int u = -1;
        int minDist = INF;

        // 找出当前未确定的最短距离的顶点
        for (int j = 0; j < vertexCount; ++j) {
            if (!s[j] && dist[j] < minDist) {
                u = j;
                minDist = dist[j];
            }
        }

        if (u == -1 || u == endIdx) break; // 找不到路径或找到终点

        s[u] = true;

        // 更新相邻顶点的距离
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

    // 输出最短路径
    cout << "从 " << vertexList[startIdx].data
        << " 到 " << vertexList[endIdx].data
        << " 的最短距离为：" << dist[endIdx] << endl;

    // 构建路径
    if (dist[endIdx] == INF) {
        cout << "没有路径可达！" << endl;
        return;
    }

    // 回溯路径
    int pathNodes[MAX_VERTEX_NUM];
    int count = 0;
    int currentIndex = endIdx;
    while (currentIndex != -1) {
        if (currentIndex >= 0 && currentIndex < vertexCount) {
            pathNodes[count++] = currentIndex;
            currentIndex = path[currentIndex];
        }
        else {
            cout << "路径索引超出范围！" << endl;
            break;
        }
    }

    // 反转路径并输出
    cout << "路径：";
    for (int i = count - 1; i >= 0; --i) {
        cout << vertexList[pathNodes[i]].data;
        if (i != 0) cout << " -> ";
    }
    cout << endl;
}

// 获取顶点索引
int Graph::getVertexIndex(const string& vertexName) const {
    for (int i = 0; i < vertexCount; ++i) {
        if (vertexList[i].data == vertexName) {
            return i;
        }
    }
    return -1; // 未找到
}

// 获取顶点名称
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
        cout << "起点不存在！" << endl;
        return;
    }

    Queue queue;  // 使用非模板 Queue（处理 BFSNode 类型）
    bool visited[MAX_VERTEX_NUM] = { false };

    queue.enqueue({ startIdx, 0 }); // 入队初始节点
    visited[startIdx] = true;

    cout << "周边地点（距离≤" << maxDistance << "米）：" << endl;
    while (!queue.isEmpty()) {
        BFSNode current = queue.dequeue();
        cout << vertexList[current.index].data << " (" << current.distance << "米)" << endl;

        ArcNode* edge = vertexList[current.index].firstedge;
        while (edge) {
            if (!visited[edge->adjvex] && (current.distance + edge->weight) <= maxDistance) {
                visited[edge->adjvex] = true;
                queue.enqueue({ edge->adjvex, current.distance + edge->weight }); // 入队新节点
            }
            edge = edge->next;
        }
    }
}

// 图管理类构造函数
GraphManager::GraphManager() : graphCount(0), currentIndex(-1) {}

// 图管理类析构函数
GraphManager::~GraphManager() {
    for (int i = 0; i < graphCount; ++i) {
        graphs[i].graph.~Graph();
    }
}

// 导入地图数据
bool GraphManager::importGraph(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        return false;
    }

    if (graphCount >= 10) {
        file.close();
        return false;
    }

    // 读取地图名称（假设文件名即为地图名称，去掉扩展名）
    size_t dotPos = fileName.find_last_of('.');
    string graphName = fileName.substr(0, dotPos);

    // 检查是否已存在同名地图
    for (int i = 0; i < graphCount; ++i) {
        if (graphs[i].name == graphName) {
            file.close();
            return false;
        }
    }

    // 清空现有图数据并创建新图
    graphs[graphCount].graph.clear();
    if (!graphs[graphCount].graph.createGraph(file)) {
        file.close();
        return false;
    }

    //添加到图列表
    graphs[graphCount].name = graphName;
    graphCount++;

    // 如果是第一个导入的地图，设置为当前地图
    if (currentIndex == -1) {
        currentIndex = 0;
    }

    file.close();
    return true;
}

// 显示当前地图信息
bool GraphManager::displayCurrentGraphInfo() const {
    if (currentIndex == -1 || currentIndex >= graphCount) {
        cout << "没有可用地图！" << endl;
        return false;
    }

    cout << "当前地图： " << graphs[currentIndex].name << endl;
    graphs[currentIndex].graph.displayGraphInfo();
    return true;
}

// 深度优先遍历
bool GraphManager::depthFirstTraversal() {
    if (currentIndex == -1 || currentIndex >= graphCount) {
        cout << "没有可用地图！" << endl;
        return false;
    }

    cout << "深度优先遍历结果：";
    graphs[currentIndex].graph.DFS(0); // 从第一个顶点开始
    return true;
}

// 广度优先遍历
bool GraphManager::breadthFirstTraversal() {
    if (currentIndex == -1 || currentIndex >= graphCount) {
        cout << "没有可用地图！" << endl;
        return false;
    }

    cout << "广度优先遍历结果：";
    graphs[currentIndex].graph.BFS(0); // 从第一个顶点开始
    return true;
}

// 查找最短路径
bool GraphManager::findShortestPath(const string& start, const string& end) {
    if (currentIndex == -1 || currentIndex >= graphCount) {
        cout << "没有可用地图！" << endl;
        return false;
    }

    Graph& currentGraph = graphs[currentIndex].graph;
    int startIdx = currentGraph.getVertexIndex(start);
    int endIdx = currentGraph.getVertexIndex(end);

    if (startIdx == -1 || endIdx == -1) {
        cout << "起点或终点不存在！" << endl;
        return false;
    }

    currentGraph.findShortestPath(startIdx, endIdx);
    return true;
}

// 显示可用地图
void GraphManager::displayAvailableGraphs() const {
    if (graphCount == 0) {
        cout << "没有可用地图！" << endl;
        return;
    }

    cout << "可用地图列表：" << endl;
    for (int i = 0; i < graphCount; ++i) {
        cout << (i + 1) << ". " << graphs[i].name << endl;
    }
}

// 切换地图
bool GraphManager::switchGraph(int index) {
    if (index < 1 || index > graphCount) {
        return false;
    }

    currentIndex = index - 1;
    return true;
}

// 获取当前地图名称
string GraphManager::getCurrentGraphName() const {
    if (currentIndex != -1 && currentIndex < graphCount) {
        return graphs[currentIndex].name;
    }
    return "";
}

// 获取地图数量
int GraphManager::getGraphCount() const {
    return graphCount;
}

// 检查是否有可用地图
bool GraphManager::isGraphAvailable() const {
    return currentIndex != -1 && currentIndex < graphCount;
}
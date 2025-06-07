#ifndef QUEUE_H
#define QUEUE_H

#include "Graph.h"  // 包含 BFSNode 定义

// 非模板队列类（专门处理 BFSNode 类型）
class Queue {
private:
    struct QueueNode {
        BFSNode data;
        QueueNode* next;
        QueueNode(const BFSNode& val) : data(val), next(nullptr) {}
    };
    QueueNode* frontNode;  // 队头指针
    QueueNode* rearNode;   // 队尾指针
    int size;          // 队列大小

public:
    Queue();                   // 构造函数
    ~Queue();                  // 析构函数
    void enqueue(const BFSNode& val); // 入队
    BFSNode dequeue();         // 出队
    BFSNode front() const;    //查看队首元素
    bool isEmpty() const;      // 检查队列是否为空
    int getSize() const;       // 获取队列大小
};

#endif
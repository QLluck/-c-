#include "Queue.h"
#include <iostream>
#include <cstdlib> // 用于 exit()

// 构造函数
Queue::Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

// 析构函数
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// 入队操作
void Queue::enqueue(const BFSNode& val) {
    QueueNode* newNode = new QueueNode(val);
    if (isEmpty()) {
        frontNode = rearNode = newNode;
    }
    else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    size++;
}

// 出队操作
BFSNode Queue::dequeue() {
    if (isEmpty()) {
        cerr << "Error: Queue is empty!" << endl;
        exit(EXIT_FAILURE); // 队列为空时终止程序（可根据需求修改）
    }
    QueueNode* temp = frontNode;
    BFSNode data = temp->data;
    frontNode = frontNode->next;
    delete temp;
    if (frontNode == nullptr) {
        rearNode = nullptr; // 队列空，更新队尾指针
    }
    size--;
    return data;
}

//查看队首元素
BFSNode Queue::front() const {
    if (isEmpty()) {
        throw runtime_error("队列为空");
    }
    return frontNode->data;
}

// 检查队列是否为空
bool Queue::isEmpty() const {
    return frontNode == nullptr;
}

// 获取队列大小
int Queue::getSize() const {
    return size;
}
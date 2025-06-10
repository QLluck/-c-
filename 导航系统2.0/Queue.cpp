#include "Queue.h"
#include <iostream>
#include <cstdlib> // ���� exit()

// ���캯��
Queue::Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

// ��������
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// ��Ӳ���
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

// ���Ӳ���
BFSNode Queue::dequeue() {
    if (isEmpty()) {
        cerr << "Error: Queue is empty!" << endl;
        exit(EXIT_FAILURE); // ����Ϊ��ʱ��ֹ���򣨿ɸ��������޸ģ�
    }
    QueueNode* temp = frontNode;
    BFSNode data = temp->data;
    frontNode = frontNode->next;
    delete temp;
    if (frontNode == nullptr) {
        rearNode = nullptr; // ���пգ����¶�βָ��
    }
    size--;
    return data;
}

//�鿴����Ԫ��
BFSNode Queue::front() const {
    if (isEmpty()) {
        throw runtime_error("����Ϊ��");
    }
    return frontNode->data;
}

// �������Ƿ�Ϊ��
bool Queue::isEmpty() const {
    return frontNode == nullptr;
}

// ��ȡ���д�С
int Queue::getSize() const {
    return size;
}
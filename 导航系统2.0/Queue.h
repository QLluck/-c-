#ifndef QUEUE_H
#define QUEUE_H

#include "Graph.h"  // ���� BFSNode ����

// ��ģ������ࣨר�Ŵ��� BFSNode ���ͣ�
class Queue {
private:
    struct QueueNode {
        BFSNode data;
        QueueNode* next;
        QueueNode(const BFSNode& val) : data(val), next(nullptr) {}
    };
    QueueNode* frontNode;  // ��ͷָ��
    QueueNode* rearNode;   // ��βָ��
    int size;          // ���д�С

public:
    Queue();                   // ���캯��
    ~Queue();                  // ��������
    void enqueue(const BFSNode& val); // ���
    BFSNode dequeue();         // ����
    BFSNode front() const;    //�鿴����Ԫ��
    bool isEmpty() const;      // �������Ƿ�Ϊ��
    int getSize() const;       // ��ȡ���д�С
};

#endif
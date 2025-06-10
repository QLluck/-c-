#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include<stdexcept>
using namespace std;

template <typename T>
class Stack {
public:
    Stack();
    ~Stack();
    void push(const T& value);//��ջ
    T pop();//��ջ
    T peek() const;//��ȡջ��Ԫ��
    bool isEmpty() const;//�ж�ջ�Ƿ�Ϊ��
    void clear();//���ջ

private:
    struct Node {
        T value;
        Node* next;
        Node(const T& val) : value(val), next(nullptr) {}
    };

    Node* topNode;
};

#endif 
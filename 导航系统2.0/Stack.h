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
    void push(const T& value);//入栈
    T pop();//出栈
    T peek() const;//获取栈顶元素
    bool isEmpty() const;//判断栈是否为空
    void clear();//清空栈

private:
    struct Node {
        T value;
        Node* next;
        Node(const T& val) : value(val), next(nullptr) {}
    };

    Node* topNode;
};

#endif 
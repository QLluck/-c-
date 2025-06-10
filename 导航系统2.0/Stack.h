#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack {
public:
    Stack();
    ~Stack();
    void push(const T& value);
    T pop();
    T peek() const;
    bool isEmpty() const;
    void clear();

private:
    struct Node {
        T value;
        Node* next;
        Node(const T& val) : value(val), next(nullptr) {}
    };

    Node* topNode;
};

#endif 
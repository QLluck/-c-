#include "Stack.h"
#include <stdexcept>

// 构造函数
template <typename T>
Stack<T>::Stack() : topNode(nullptr) {}

// 析构函数
template <typename T>
Stack<T>::~Stack() {
    clear();
}

// 入栈
template <typename T>
void Stack<T>::push(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = topNode;
    topNode = newNode;
}

// 出栈
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw runtime_error("栈为空");
    }

    Node* temp = topNode;
    T value = temp->value;
    topNode = temp->next;
    delete temp;
    return value;
}

// 查看栈顶元素
template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw runtime_error("栈为空");
    }
    return topNode->value;
}

// 判断栈是否为空
template <typename T>
bool Stack<T>::isEmpty() const {
    return topNode == nullptr;
}

// 清空栈
template <typename T>
void Stack<T>::clear() {
    while (!isEmpty()) {
        pop();
    }
}

// 显式实例化
template class Stack<int>;
template class Stack<string>;
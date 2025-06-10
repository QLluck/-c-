#include "Stack.h"
#include <stdexcept>

// ���캯��
template <typename T>
Stack<T>::Stack() : topNode(nullptr) {}

// ��������
template <typename T>
Stack<T>::~Stack() {
    clear();
}

// ��ջ
template <typename T>
void Stack<T>::push(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = topNode;
    topNode = newNode;
}

// ��ջ
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw runtime_error("ջΪ��");
    }

    Node* temp = topNode;
    T value = temp->value;
    topNode = temp->next;
    delete temp;
    return value;
}

// �鿴ջ��Ԫ��
template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw runtime_error("ջΪ��");
    }
    return topNode->value;
}

// �ж�ջ�Ƿ�Ϊ��
template <typename T>
bool Stack<T>::isEmpty() const {
    return topNode == nullptr;
}

// ���ջ
template <typename T>
void Stack<T>::clear() {
    while (!isEmpty()) {
        pop();
    }
}

// ��ʽʵ����
template class Stack<int>;
template class Stack<string>;
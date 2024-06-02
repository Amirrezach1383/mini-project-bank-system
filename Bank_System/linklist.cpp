#include "linklist.h"

/// =========== Node Class Functions ==========

template<class T>
Node<T>::Node(T data) {
    nextNode = nullptr;
    previousNode = nullptr;
    this->data = data;
}

/// Setters Functions
template<class T>
void Node<T>:: setData(T data) {
    this->data = data;
}
template<class T>
void Node<T>::setNextNode(Node<T> * nextNode) {
    this->nextNode = nextNode;
}
template<class T>
void Node<T>::setPreviousNode(Node<T> * previousNode) {
    this->previousNode = previousNode;
}

/// Getter Functions
template<class T>
T Node<T>::getData() {
    return data;
}
template<class T>
Node<T>* Node<T>::getNextNode() {
    return nextNode;
}
template<class T>
Node<T>* Node<T>::getPreviousNode() {
    return previousNode;
}


/// ========= LinkList Class Functions ========

template<class T>
LinkList<T>:: LinkList () {
    size = 0;
    headNode = nullptr;
    tailNode = nullptr;

}
template<class T>
LinkList<T>::~LinkList () {
    Node<T> *tmp = headNode, *tp;

    while (tmp != nullptr) {
        tp = tmp;
        tmp = tmp->getNextNode();
        delete tp;
    }
    size = 0;
    headNode = nullptr;
    tailNode = nullptr;

}

/// Getter Functions
template<class T>
int LinkList<T>::getSize() {
    return size;
}
template<class T>
Node<T> * LinkList<T>::getHeadNode() {
    return headNode;
}
template<class T>
Node<T> * LinkList<T>::getTailNode() {
    return tailNode;
}

/// PushBack
template<class T>
void LinkList<T>::pushBack(T data) {
    Node<T> *tmp = new Node<T> (data);
    tmp->setPreviousNode(tailNode);

    if (tailNode != nullptr)
        tailNode->setNextNode(tmp);

    tmp->setNextNode(nullptr);
    tailNode = tmp;
    size++;

    if (headNode == nullptr)
        headNode = tmp;

}

/// pop back
template<class T>
bool LinkList<T>::popBack () {
    if (size != 0) {
        Node<T> * tmp = tailNode;

        if (tmp->getPreviousNode() != nullptr) {
            tailNode = tmp->getPreviousNode();
            tailNode->setNextNode(nullptr);

        } else {
            headNode = nullptr;
            tailNode = nullptr;
        }
        delete tmp;
        size --;
        return true;
    }

    return false;
}


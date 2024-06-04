#ifndef LINKLIST_H
#define LINKLIST_H
#include <users.h>

template <class T>
class Node {
private:
    T data;
    Node<T>* nextNode;
    Node<T> * previousNode;

public:
    Node(T data){
        nextNode = nullptr;
        previousNode = nullptr;
        this->data = data;
    }

    /// Setters
    void setData(T data) {
        this->data = data;
    }
    void setNextNode(Node<T> * nextNode){
        this->nextNode = nextNode;
    }
    void setPreviousNode(Node<T> * previousNode){
        this->previousNode = previousNode;
    }

    /// Getters
    T getData(){
        return data;
    }
    Node * getNextNode(){
        return nextNode;
    }
    Node * getPreviousNode(){
        return previousNode;
    }

};

template <class T>
class LinkList {
private:
    Node<T> * headNode;
    Node<T> * tailNode;
    int size;

public:
    LinkList<T>() {
        size = 0;
        headNode = nullptr;
        tailNode = nullptr;
    }
    ~LinkList<T>(){
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

    /// Push Back
    void pushBack(T data){
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

    ///Pop Back
    bool popBack(){
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

    /// Getter
    Node<T> * getTailNode(){
        return tailNode;
    }
    Node<T> * getHeadNode(){
        return headNode;
    }
    int getSize() {
        return size;
    }
};
LinkList<Users> userList;
#endif // LINKLIST_H

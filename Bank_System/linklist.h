#ifndef LINKLIST_H
#define LINKLIST_H

template <typename T>
class Node {
private:
    T data;
    Node<T>* nextNode;
    Node<T> * previousNode;

public:
    Node(T data);

    /// Setters
    void setData(T data);
    void setNextNode(Node<T> * nextNode);
    void setPreviousNode(Node<T> * previousNode);

    /// Getters
    T getData();
    Node * getNextNode();
    Node * getPreviousNode();
};

template <typename T>
class LinkList {
private:
    Node<T> * headNode;
    Node<T> * tailNode;
    int size;

public:
    LinkList<T>();
    ~LinkList<T>();

    /// Push Back
    void pushBack(T data);

    ///Pop Back
    bool popBack();

    /// Getter
    Node<T> * getTailNode();
    Node<T> * getHeadNode();
    int getSize();
};

#endif // LINKLIST_H

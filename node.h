

#ifndef NODE_H
#define NODE_H

#include "linklist.h"
template<typename T>
class LinkList;


template <typename T>
struct Node{

private:
friend class LinkList<T>;

public:
T val;
Node<T> * next;

Node(T data) : val(data), next(nullptr){}

Node() : next(nullptr) {} 

bool operator==(const Node<T>& other)
{
 return (this->val == other.val && this->next == other.next);
}


};

#endif


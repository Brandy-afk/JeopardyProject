

#ifndef BINNODE_H
#define BINNODE_H

template<typename T>
class BinTree;


template<typename T>
class BinNode
{
private:
friend class BinTree<T>;

T val;
BinNode<T> * left;
BinNode<T> * right;


public:
BinNode(T v) :val(v), left(nullptr), right(nullptr) {}
BinNode() : left(nullptr), right(nullptr) {}
~BinNode() {}


};

#endif

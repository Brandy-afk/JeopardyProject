

#ifndef BINTREE_H
#define BINTREE_H
#include "binnode.h"
#include <ostream>



template<typename T>
class BinTree
{

typedef void (*process)(T item, int, int&);

private:
BinNode<T>* root;
int counter = 0;

void free(BinNode<T>* root);
void inOrderTraverse(BinNode<T>* root, process action, int catagoryID);
BinNode<T>* addRecursive(BinNode<T>* node, T value);
void writeRecursive(std::ofstream& stream, BinNode<T>* node) const;


public:
BinTree() : root(nullptr) {}
~BinTree() { free(root); }
BinTree(const BinTree<T>& source);

bool isEmpty();
void add(T value) 
{
  root = addRecursive(root, value);
}

void inOrder(process action, int value);
BinNode<T>* copyTree(const BinNode<T>* root);


BinTree<T>& operator=(const BinTree<T>& other);


bool readFile(const std::string& fileName);
bool writeFile(const std::string& fileName) const;

};

#include "bintree.tem"
#endif

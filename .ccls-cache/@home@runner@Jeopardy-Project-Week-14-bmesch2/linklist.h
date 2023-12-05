

#ifndef LINKLIST_H
#define LINKLIST_H
#include "node.h"
#include <iostream>

template <typename T>
class LinkList{

private:
Node<T> * head;
Node<T> * tail;
size_t size;

void free();
Node<T> * alloc(T data);


public:

LinkList() : head(nullptr), tail(nullptr), size(0) {}
LinkList(const LinkList<T>& other);
~LinkList();

void prepend(T val);
void append(T val);

bool isEmpty();
// Node<T>* find(T data);
bool findByData(T data);
T at(int index);
T getRandomData();

bool removeFirst();
bool remove(T data);

void printAll();
bool writeFile(const std::string& fileName)const ;
bool readFile(const std::string& fileName);

LinkList<T>& operator=(const LinkList<T>& rhs);

int getSize() const;


};

#include "linklist.tem"
#endif 

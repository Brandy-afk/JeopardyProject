

#include "record.h"
#include <iostream>
#include <string>

Record::Record() : std::string() {}
Record::Record(const std::string &str) : std::string(str) {}
Record::Record(const std::string &str, size_t pos, size_t len)
    : std::string(str, pos, len) {}
Record::Record(const char *s) : std::string(s) {}
Record::Record(const char *s, size_t n) : std::string(s, n) {}
Record::Record(size_t n, char c) : std::string(n, c) {}

Record::~Record()
{
  free();
}

void Record::free()
{
  if(splitPointer != nullptr)
  {
    delete [] splitPointer;
    splitPointer = nullptr;
  }


}

void Record::alloc(size_t newSize)
{
  Record * temp = new Record[newSize];

  for(int i = 0; i < std::min(count, newSize); ++i)
    {
      temp[i] = splitPointer[i];
    }

  free();

  splitPointer = temp;
  count = newSize;

  if(newSize < pointerSize)
  {
    pointerSize = newSize;
  }
}

Record Record::upper() const{
  std::string copy = *this;
  for (int i = 0; i < copy.size(); ++i) {
    copy[i] = std::toupper(copy[i]);
  }
  return copy;
}

Record Record::lower() const{
  std::string copy = *this;
  for (int i = 0; i < copy.size(); ++i) {
    copy[i] = std::tolower(copy[i]);
  }
  return copy;
}

int Record::compare(Record &record) const{
  std::string thisCopy = this->upper();
  std::string strCopy = record.upper();

  return thisCopy.compare(strCopy);
}


size_t Record::getCount() const
{
  return count;
}

Record* Record::split(const char seperator){

  int splits = 1;
  for (size_t i = 0; i < this->size(); ++i) 
  {
    if (at(i) == seperator)
    {
      ++splits;
    }
  }


  alloc(splits);

  size_t start = 0;
  size_t currentSplit = 0;

  for(size_t i = 0; i < this->size() ; i++)
  {
    if(at(i) == seperator)
    {
      splitPointer[currentSplit] = Record(this->substr(start, i - start));
      start = i + 1;
      ++currentSplit;
    }
  }

  splitPointer[currentSplit] = this->substr(start);

  return splitPointer;
}


std::istream &operator>>(std::istream &in, Record &record) {
  if (in.peek() == '\n')
    in.ignore(1);

  std::getline(in, record, '\n');

  return in;
}



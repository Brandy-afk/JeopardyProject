
#ifndef RECORD_H
#define RECORD_H

#include <string>

class Record : public std::string {

private:

  Record * splitPointer = nullptr;
  size_t count = 0;
  size_t pointerSize = 0;

  void alloc(size_t newSize);
  void free();


public:

  Record();
  Record(const std::string &str);
  Record(const std::string &str, size_t pos, size_t len = npos);
  Record(const char *s);
  Record(const char *s, size_t n);
  Record(size_t n, char c);
  ~Record();

  Record upper() const;
  Record lower() const;
  Record* split(const char seperator = ' ');
  size_t getCount() const;
  int compare(Record &record) const;

  friend std::istream &operator>>(std::istream &in, Record &record);
};

#endif

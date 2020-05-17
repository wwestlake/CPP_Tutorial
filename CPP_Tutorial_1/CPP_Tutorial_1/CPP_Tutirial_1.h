#ifndef __CPP_TUTORIAL_1_H
#define __CPP_TUTORIAL_1_H


#include <cstdint>

#include <string>
#include <list>

typedef uint8_t byte;

typedef std::list<std::string> strlist;

int add(int a, int b);
int addRef(const int& a, const int& b);
void addRef2(const int& a, const int& b, int& result);
void addPtr(int* a, int* b, int* result);
void addArray(int len, int* vals, int& retval);
int test1();




#endif // __CPP_TUTORIAL_1_H




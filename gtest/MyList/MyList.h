#ifndef GTEST_MYLIST_MYLIST_H
#define GTEST_MYLIST_MYLIST_H

#include "CNode.h"

CNode* CreateList(int count, const int* vals);
void print(CNode *pf);
int size(CNode *pf);
CNode* del(CNode **pf, int n);
bool comp(CNode*, CNode*);
bool cmp(list p, list b);
void srt(CNode **pf);
class list {
public: 
  double* data; 
  int* pdata; 
  int cur; 
  int size;
  list(int n);
  ~list();
  void MoveNext();
  void Add(double a);
  void Del();
  void del1(int n);
  void print();
private: 
  void DelFreeNode(int i);
  void AddNewNode(int i, int j);
};
#endif  // GTEST_MYLIST_MYLIST_H

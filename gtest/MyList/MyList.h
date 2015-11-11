#ifndef GTEST_MYLIST_MYLIST_H
#define GTEST_MYLIST_MYLIST_H

#include "CNode.h"

CNode* CreateList(int count, const int* vals);
void print(CNode *pf);
int size(CNode *pf);
CNode* del(CNode **pf, int n);
bool comp(CNode*, CNode*);
#endif  // GTEST_MYLIST_MYLIST_H

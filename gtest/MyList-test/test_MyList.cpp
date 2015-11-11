#include "MyList.h"
#include <gtest.h>
#include <iostream>

using namespace std;
TEST(MyList, CreateEmptyList) {
  CNode *head = CreateList(0, 0);
  CNode *expected_head = 0;
  EXPECT_EQ(expected_head, head);
}

TEST(MyList, CreateList) {
  const int kListSize = 10;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
    vals[i] = i + 1;
  CNode *head = CreateList(kListSize, vals);

  int k = 0;
  while (head != 0) {
    EXPECT_EQ(vals[k], head->val);
    head = head->next;
    ++k;
  }
  EXPECT_EQ(kListSize, k);
}
TEST(MyList, functionDel) {
  const int kListSize = 5;
  int vals[kListSize];
  int n = 2;
  for (int i = 0; i < 5; ++i)
    vals[i] = i + 1;
  CNode *p = CreateList(kListSize, vals);
  for (int i = 0; i < 4; ++i) {
    if (i >= (5 - n))
      vals[i] = i + 2;
    else
      vals[i] = i + 1;
  }
  CNode *b = CreateList(kListSize - 1, vals);
  print(p);
  cout << endl;
  print(b);
  cout << endl;
  CNode *e = del(&p, n);
  print(e);
  EXPECT_EQ(true, comp(b, e));
}

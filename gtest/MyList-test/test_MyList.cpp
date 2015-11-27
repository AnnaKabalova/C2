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

TEST(MyList, can_del_first_element) {
  const int kListSize = 5;
  int vals[kListSize];
  int n = 5;
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

TEST(MyList, can_del_last_element) {
  const int kListSize = 5;
  int vals[kListSize];
  int n = 1;
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

TEST(MyList, cant_del_element_with_too_large_itdex) {
  const int kListSize = 5;
  int vals[kListSize];
  int n = 6;
  for (int i = 0; i < 5; ++i)
    vals[i] = i + 1;
  CNode *p = CreateList(kListSize, vals);
  ASSERT_ANY_THROW(del(&p, n));
}

TEST(MyList, cant_del_element_with_negative_itdex) {
  const int kListSize = 5;
  int vals[kListSize];
  int n = -6;
  for (int i = 0; i < 5; ++i)
    vals[i] = i + 1;
  CNode *p = CreateList(kListSize, vals);
  ASSERT_ANY_THROW(del(&p, n));
}

TEST(MyList, cant_del_element_from_empty_node) {
  const int kListSize = 5;
  int vals[kListSize];
  int n = 2;
  for (int i = 0; i < 5; ++i)
    vals[i] = i + 1;
  CNode *p = CreateList(0, vals);
  ASSERT_ANY_THROW(del(&p, n));
}
TEST(MyList, sort) {
  const int kListSize = 5;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
  {
	  if (i%2==0)
		  vals[i] = i + 10;
	  else
          vals[i] = i + 1;
  }
  CNode *head = CreateList(kListSize, vals);
  print(head);
  sort(&head);
  print(head);
}
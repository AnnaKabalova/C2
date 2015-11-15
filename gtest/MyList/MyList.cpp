#include "CNode.h"
#include "MyList.h"
#include <iostream>

using namespace std;
CNode* CreateList(int count, const int* vals) {
  if (count <= 0) return 0;
  CNode *head = new CNode;
  head->val = vals[0];
  CNode *prev = head;
  for (int i = 1; i < count; ++i) {
    CNode *node = new CNode;
    node->val = vals[i];
    prev->next = node;
    prev = node;
  }
  prev->next = 0;
  return head;
}

void print(CNode *pf) {
  while (pf != 0) {
    cout << pf->val << ' ';
    pf = pf->next;
  }
}

int size(CNode *pf) {
  int n = 0;
  while (pf != 0) {
    pf = pf->next;
    n++;
  }
  return n;
}

CNode* del(CNode **pf, int n) {
  if ((n<0 || n>size(*pf)) || *pf==NULL)
    throw std::exception("negative or too large index");
  int f = size(*pf) - n + 1;
  CNode *cur = *pf,
  *p = NULL;
  while (cur && cur->val != f) {
    p = cur;
    cur = cur->next;
  }
  if (cur) {
    if (p)
      p->next = cur->next;
    else
      *pf = cur->next;
    delete cur;
  }
  return *pf;
}
bool comp(CNode *p, CNode *b) {
  if (size(p) != size(b))
    return false;
  else
    while (p != 0 && b != 0) {
      if ((p->val) != (b->val))
        return false;
      p = p->next;
      b = b->next;
    }
  return true;
}

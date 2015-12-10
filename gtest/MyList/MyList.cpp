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
  cout<<endl;
}

int size(CNode *pf) {
  int n = 0;
  while (pf != 0) {
    pf = pf->next;
    n++;
  }
  return n;
}

int size(CNode **pff) {
  CNode*pf=*pff;
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

void srt(CNode **pf) {
  if (*pf == 0) {
    throw std::exception("Empty node");
  }

  if ((*pf)->next == 0) {
    return;
  }

  if ((*pf)->next->next == 0) {
    if ((*pf)->val > (*pf)->next->val) {
      CNode *tmp = (*pf)->next;
      (*pf)->next->next = (*pf);
      (*pf)->next = 0;
      (*pf) = tmp;
    }
    return;
  }
//первый элемент
  CNode *tmp;
  int f = 0;
  while (f == 0) {
    f = 1;
    tmp = (*pf);
    if (tmp->val > tmp->next->val) {
      f = 0;
      CNode *tmp2 = (*pf)->next;
      CNode *tmp3 = (*pf)->next->next;
      (*pf)->next->next = (*pf);
      (*pf)->next = tmp3;
	  (*pf) = tmp2;
    }
//для остальных элементов
    while (tmp->next->next != 0) {
      if (tmp->next->val > tmp->next->next->val) {
        CNode *tmp1, *tmp2, *tmp3;
          f = 0;
          tmp1 = tmp->next;
          tmp2 = tmp->next->next;
          tmp3 = tmp->next->next->next;
          tmp2->next = tmp1;
          tmp1->next = tmp3;
          tmp->next = tmp2;
       }
       tmp = tmp->next;
    }
  }
}

list::list(int n) {
  if (n <= 0)
    throw std::exception("Wrong size");
  data = new double[n + 2];
  pdata = new int[n + 2];
  cur = 0;
  pdata[0] = 0;
  for (int i = 1; i < n + 1; i++)
    pdata[i] = i + 1;
  pdata[n + 1] = 1;
}

list::~list() {
  delete[]data;
  delete[]pdata;
}

void list::MoveNext() {
  cur = pdata[cur];
}

void list::Add(double a) {
  if (pdata[1] == 1)
    throw std::exception("Full List");
  int ine = pdata[1]; //индекс пустого звена
  this->DelFreeNode(1);
  this->AddNewNode(cur, ine);
    data[ine] = a;
}

void list::DelFreeNode(int i) {
  int cur1 = pdata[i];
  pdata[i] = pdata[cur1];
  pdata[cur1] = -1;
}

void list::AddNewNode(int i, int j) {
  int next = pdata[i];
  pdata[i] = j;
  pdata[j] = next;
}

void list::Del() {
  if (pdata[0] == 0)
    throw std::exception("Empty List");
  if (pdata[cur] == 0)
    this->MoveNext();
  int ine = pdata[cur]; //Номер, который удаляем
    this->DelFreeNode(cur);
    this->AddNewNode(1, ine);
}

void list::print() {
  int i = pdata[0];
  while (i != 0) {
    cout << data[i] << endl;
    i = pdata[i];
  }
}

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

CNode* sort(CNode **pf) {
	//int n=size(*pf);
	CNode* tmp = *pf;
	while (tmp!=0)
	{
		CNode* tmp1 = tmp;
		CNode* tmp2 = tmp;
		CNode* min1=NULL;
		int min=tmp1->val;
		while(tmp1->next!=0) {
			if (min>tmp1->next->val) {
				min=tmp1->next->val;
				min1=tmp1;
			}
			tmp1=tmp1->next;
		}
		
			CNode* tmp3 = min1->next;
			CNode* tmp4 = tmp;
			min1->next=tmp4;
			tmp4=tmp3->next;
			print(*pf);
			CNode* tmp5 = tmp->next;	
			tmp=tmp3;
			tmp->next=tmp5;

			/*tmp4->next=min1->next->next;

			min1->next->next=tmp3->next;
			min1->next
			tmp3->next->next=tmp->next;
			tmp=tmp3;*/
		
		print(*pf);
			break;
	}
	CNode* b = tmp;
	tmp=tmp->next;
	while (tmp!=0)
	{
		CNode* tmp1 = tmp;
		CNode* tmp2 = tmp;
		CNode* min1=NULL;
		int min=tmp1->val;
		while(tmp1->next!=0) {
			if (min>tmp1->next->val) {
				min=tmp1->next->val;
				min1=tmp1;
			}
			tmp1=tmp1->next;
		}

			CNode* tmp3 = min1->next;
			CNode* tmp4 = tmp;
			min1->next=tmp4;
			tmp4=tmp3->next;
			
			CNode* tmp5 = tmp->next;	
			b->next=tmp3;
			tmp3->next=tmp5;

			/*CNode* tmp3 = min1;
			min1->next=tmp;
			tmp3->next->next=tmp->next;
			b->next=tmp3;
			/*tmp=min1->next;
			min1=tmp->next;*/
		
		print(*pf);
		tmp=tmp->next;
		b=b->next;
	}
	return *pf;
}
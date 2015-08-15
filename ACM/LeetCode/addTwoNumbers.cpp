#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

class Solution
{
	public:
		ListNode *addTwoNumbers(ListNode *L1, ListNode *L2)
		{
			ListNode *L = new ListNode((L1->val + L2->val) % 10);
			ListNode *head = L;
			int tmp = (L1->val + L2->val) / 10;
			while(L1->next != NULL && L2->next != NULL)
			{
				L1 = L1->next;
				L2 = L2->next;
				L->next = new ListNode((L1->val + L2->val + tmp) % 10);
				L = L->next;
				tmp = (L1->val + L2->val + tmp)/10;
			}
			while(L1->next != NULL)
			{
				L1 = L1->next;
				L->next = new ListNode((L1->val + tmp) % 10);
				L = L->next;
				tmp = (L1->val + tmp) / 10;
			}

			while(L2->next != NULL)
			{
				L2= L2->next;
				L->next = new ListNode((L2->val + tmp) % 10);
				L = L->next;
				tmp = (L2->val + tmp) / 10;
			}
			if(tmp != 0)
				L->next = new ListNode(tmp);
			return head;
		}
};

int main()
{
	Solution sol;
	ListNode *l1 = new ListNode(2),*l2 = new ListNode(8);
	ListNode *h1 = l1, *h2 = l2;
/*	int n1[2] = {4,3};
	for(int i = 0; i < 2; ++i)
	{
		l1->next = new ListNode(n1[i]);
		l1 = l1->next;
	}*/
	ListNode *t1 = h1, *t2 = h2;
	while(t1 != NULL)
	{
		printf("%d ",t1->val);
		t1 = t1->next;
	}
	cout << endl;
	while(t2 != NULL)
	{
		printf("%d ",t2->val);
		t2 = t2->next;
	}
	cout << endl;
	ListNode *ans = sol.addTwoNumbers(h1,h2);
	while(ans != NULL)
	{
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;
	return 0;
}

				
				

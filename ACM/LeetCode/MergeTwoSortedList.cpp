#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x): val(x),next(NULL) {}
};

class Solution
{
	public:
		ListNode *mergeTwoLists(ListNode *l1,ListNode *l2)
		{
			if(l1 == NULL)
				return l2;
			if(l2 == NULL)
				return l1;
			ListNode * tmp = l2;
			ListNode * head = l1;
			if(l1->val > l2->val)
			{
				tmp = l2->next;
				l2->next = l1;
				head = l2;
			}
			l2 = tmp;
			l1 = head;
			while(l1 != NULL && l2 != NULL)
			{
			//	cout << l1->val << " " << l2->val << " " << l1->next->val << endl;
				if(l1->next == NULL)
				{
					l1->next = l2;
					break;
				}
				if(l2->val >= l1->val && l2->val < l1->next->val)
				{
					tmp = l2->next;
					l2->next = l1->next;
					l1->next = l2;
					l2 = tmp;
				}
				l1 = l1->next;
			}
			return head;
		}
};

int main()
{
	ListNode * l1 = new ListNode(3);
	l1->next = new ListNode(5);
	l1->next->next = new ListNode(6);
	l1->next->next->next = new ListNode(9);

	ListNode * l2 = new ListNode(2);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	l2->next->next->next = new ListNode(8);
	l1 = NULL;
	ListNode * tmp = l1;
	while(tmp != NULL)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
	tmp = l2;
	while(tmp != NULL)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
	Solution sol;
	tmp = sol.mergeTwoLists(l1,l2);
	cout << "ans " << endl;
	while(tmp != NULL)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
	return 0;
}



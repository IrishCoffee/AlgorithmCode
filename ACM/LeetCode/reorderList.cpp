#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
	public:
		void reorderList(ListNode *head)
		{
			ListNode * fast = head;
			ListNode * slow = head;
			ListNode * cur, * pre, * tmp, * h1, * h2;
			h1 = head;
			//get median 
			if(fast == NULL || fast->next == NULL || fast->next->next == NULL)
				return;
			fast = fast->next->next;
			while(fast != NULL && fast->next != NULL)
			{
				slow = slow->next;
				fast = fast->next->next;
			}
			if(fast == NULL)// 
				cur = slow->next;
			else
				cur = slow->next->next;
			//reverse
			pre = cur->next;
			cur->next = NULL;
			if(pre == NULL) h2 = cur;
			else
			{
				while(pre != NULL)
				{
					tmp = pre->next;
					if(tmp == NULL)
						h2 = pre;
					pre->next = cur;
					cur = pre;
					pre = tmp;
				}
			}
			//merge two list
			while(h2 != NULL)
			{
				tmp = h1->next;
				h1->next = h2;
				h2 = h2->next;
				h1->next->next = tmp;
				h1 = tmp;
			}
			if(h1 != NULL)
				h1->next = NULL;
			else
				h1 == NULL;
			return;
		}
};

int main()
{
	Solution sol;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	//	head->next->next->next = new ListNode(4);
	//	head->next->next->next->next = new ListNode(5);
	//	head->next->next->next->next->next = new ListNode(6);
	//	head->next->next->next->next->next->next = new ListNode(7);
	ListNode * tmp = head;
	while(head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	head = tmp;
	sol.reorderList(head);
	while(head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}

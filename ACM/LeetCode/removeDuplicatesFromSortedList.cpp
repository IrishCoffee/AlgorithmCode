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
		ListNode *deleteDuplicates(ListNode * head)
		{
			if(head == NULL)
				return head;
			ListNode * pre = head;
			ListNode * cur = head->next;
			while(cur != NULL)
			{
				if(pre->val == cur->val)
					pre->next = cur->next;
				else
					pre = cur;
				cur = cur->next;
			}
			return head;
		}

};

int main()
{
	Solution sol;
	ListNode *head = new ListNode(1);
//	head->next = new ListNode(1);
//	head->next->next = new ListNode(2);
//	head->next->next->next = new ListNode(3);
//	head->next->next->next->next = new ListNode(3);
//	head->next->next->next->next->next = new ListNode(4);
//	head->next->next->next->next->next->next = new ListNode(4);
	ListNode * tmp = head;
	while(head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	head = tmp;
	head = sol.deleteDuplicates(head);
	while(head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}

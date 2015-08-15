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
			//get the new head
			ListNode * pre = head->next;
			ListNode * cur;
			ListNode * cur_next;
			while(pre != NULL)
			{
				while(pre != NULL)
				{
					if(pre->val != head->val)
						break;
					pre = pre->next;
				}
				if(pre != head->next)
				{
					if(pre == NULL)
						return NULL;
					head = pre;
					pre = head->next;
				}
				else
					break;
			}

			pre = head;
			cur = pre->next;
			if(cur == NULL)
				return head;
			else
				cur_next = cur->next;
			while(cur != NULL)
			{
				bool duplicate = false;
				while(cur->next != NULL)
				{
					if(cur->next->val == cur->val) 
					{
						duplicate = true;
						cur = cur->next;
					}
					else
						break;
				}
				if(duplicate)
				{
					pre->next = cur->next;
					cur = cur->next;
				}
				else
				{
					pre = pre->next;
					cur = pre->next;
				}
			}
			return head;
		}
};

int main()
{
	Solution sol;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next = new ListNode(3);
		head->next->next->next->next->next->next = new ListNode(5);
		head->next->next->next->next->next->next->next = new ListNode(5);
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

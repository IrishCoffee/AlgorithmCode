#include <iostream>
#include <cstdio>
#include <cstdlib>
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
		ListNode * rotateRight(ListNode *head,int k)
		{
			if(head == NULL || k == 0)
				return head;
			ListNode * fast = head;
			int len = 0;
			while(fast != NULL)
			{
				fast = fast->next;
				len++;
			}
			if(len > k)
				return f(head,k);
			else
				return f(head,k % len);
		}
		ListNode * f(ListNode *head,int k)
		{
			if(k == 0) return head;
			ListNode * fast = head;
			ListNode * slow = head;
			for(int i = 0; i < k; ++i)
				fast = fast->next;
			while(fast->next != NULL)
			{
				fast = fast->next;
				slow = slow->next;
			}
			ListNode * newhead = slow->next;
			slow->next = NULL;
			fast->next = head;
			return newhead;
		}
};

int main()
{
	ListNode * head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	Solution sol;
	int k;
	cin >> k;
	head = sol.rotateRight(head,k);
	while(head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}

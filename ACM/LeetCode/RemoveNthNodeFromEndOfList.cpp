#include <iostream>
#include <cstdio>
#include <cstdlib>
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
		ListNode *removeNthFromEnd(ListNode *head, int n)
		{
			ListNode *first = head;
			ListNode *second = head;
			while(n--)
				first = first->next;
			if(first == NULL)
			{
				head = head->next;
				return head;
			}
			while(first->next != NULL)
			{
				first = first->next;
				second = second->next;
			}
			second->next = second->next->next;
			return head;
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
	head = sol.removeNthFromEnd(head,5);
	while(head != NULL)
	{
		cout << head->val << " " ;
		head = head->next;
	}
	cout << endl;
}


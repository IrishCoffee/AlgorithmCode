#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL) {}
};
class Solution
{
	public:
		bool hasCycle(ListNode *head)
		{
			if(head == NULL || head->next == NULL)
				return false;
			ListNode *p1 = head;
			ListNode *p2 = head->next;
			while(p1 != NULL && p2 != NULL)
			{
				if(p1 == p2)
					return true;
				p1 = p1->next;
				if(p2->next != NULL)
					p2 = p2->next->next;
				else
					p2 = NULL;
			}
			return false;
		}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = head;
//	head->next->next = new ListNode(3);
//	head->next->next->next = new ListNode(4);
//	head->next->next->next->next = new ListNode(5);
//	head->next->next->next->next->next = new ListNode(6);
//	head->next->next->next->next->next->next = new ListNode(7);
//	head->next->next->next->next->next->next->next = head->next->next->next;
	Solution sol;
	cout << sol.hasCycle(head) << endl;
	return 0;
}



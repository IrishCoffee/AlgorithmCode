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
		ListNode *detectCycle(ListNode *head)
		{
			ListNode *ans,*slow,*fast;
			if(head == NULL || head->next == NULL)
				return NULL;
			slow = head;
			fast = head;
			bool flag = false;
			while(fast && fast->next)
			{
				fast = fast->next->next;
				slow = slow->next;
				if(slow == fast)
					break;
			}
			if(slow != fast)
				return NULL;
			fast = head;
			while(slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return fast;
		}
};

int main()
{
	ListNode * head = new ListNode(1); 
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = head->next->next;
	Solution sol;
	ListNode *ans = sol.detectCycle(head);
	if(ans == NULL)
		cout << "NULL" << endl;
	else
		cout << ans->val << endl;
	return 0;
}

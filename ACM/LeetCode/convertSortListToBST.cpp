#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL) {}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

class Solution
{
	public:
		int length(ListNode *head)
		{
			int len = 0;
			while(head)
			{
				len++;
				head = head->next;
			}
			return len;
		}
		ListNode *getNode(ListNode *head,int len)
		{
			for(int i = 0; i < len; ++i)
				head = head->next;
			return head;
		}

		TreeNode *sortedListToBST(ListNode *head)
		{
			if(head == NULL)
				return NULL;
			TreeNode * root = build(head,0,length(head)-1);
			return root;
		}
		TreeNode *build(ListNode * head,int left,int right)
		{
			if(left > right)
				return NULL;
			int mid = (left + right)/ 2;
			ListNode * node = getNode(head,mid-left);
			TreeNode * root = new TreeNode(node->val);
			root->left = build(head,left,mid-1);
			root->right = build(node->next,mid+1,right);
			return root;
		}
};
void order(TreeNode * root)
{
	if(root == NULL)
		return;
	order(root->left);
	order(root->right);
	cout << root->val << " ";
	return;
}
int main()
{
	ListNode * head = new ListNode(0);
	ListNode * tmp = head;
	for(int i = 1; i < 10; ++i)
	{
		tmp->next = new ListNode(i);
		tmp = tmp->next;
	}
	Solution sol;
	TreeNode * root = sol.sortedListToBST(head);
	order(root);
	cout << endl;
	return 0;
}
			

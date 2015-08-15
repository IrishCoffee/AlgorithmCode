#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

class Solution
{
	public:
		bool isSameTree(TreeNode * p,TreeNode * q)
		{
			bool flag = true;
			dfs(p,q,flag);
			return flag;
		}
		void dfs(TreeNode * p,TreeNode * q,bool &flag)
		{
			if(!flag) return;
			if(p == NULL && q == NULL) return;
			if(p == NULL || q == NULL)
			{
				flag = false;
				return;
			}
			if(p->val != q->val)
			{
				flag = false;
				return;
			}
			if(p->left == NULL && q->left == NULL) goto checkRight;
			if(p->left == NULL || q->left == NULL)
			{
				flag = false;
				return;
			}
			dfs(p->left,q->left,flag);
checkRight:
			if(p->right == NULL && q->right == NULL) return;
			if(p->right == NULL || q->right == NULL)
			{
				flag = false;
				return;
			}
			dfs(p->right,q->right,flag);
			return;
		}
};

int main()
{
	Solution sol;
	TreeNode * p = new TreeNode(1);
	p->left = new TreeNode(2);
	p->left->right = new TreeNode(4);
	p->right = new TreeNode(3);
	p->right->left = new TreeNode(5);
	p->right->left->left = new TreeNode(6);
	p->right->left->right = new TreeNode(7);
	p->right->left->right->left = new TreeNode(8);
	
	TreeNode * q = new TreeNode(1);
	q->left = new TreeNode(2);
	q->left->right = new TreeNode(4);
	q->right = new TreeNode(3);
	q->right->left = new TreeNode(5);
	q->right->left->left = new TreeNode(6);
	q->right->left->right = new TreeNode(7);
	q->right->left->right->left = new TreeNode(8);
	cout << sol.isSameTree(p,q) << endl;
	return 0;
}

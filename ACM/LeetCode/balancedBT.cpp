#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

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
		bool isBalanced(TreeNode *root)
		{
			if(root == NULL)
				return true;
			int l_h = dfs(root->left,0);
			int r_h = dfs(root->right,0);
			if(l_h == -1 || r_h == -1 || fabs(l_h - r_h) > 1)
				return false;
			else
				return true;
		}
		int dfs(TreeNode * root,int h)
		{
			if(root == NULL)
				return h;
			int l_h = dfs(root->left,h+1);
			int r_h = dfs(root->right,h+1);
			if(l_h == -1 || r_h == -1 || fabs(l_h - r_h) > 1)
				return -1;
			else
				return max(l_h,r_h);
		}
};

int main()
{
	Solution sol;
	TreeNode * root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(6);
	root->right->right->right = new TreeNode(7);
	root->right->right->right->right = new TreeNode(8);
	cout << sol.isBalanced(root) << endl;
	return 0;
}

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
		bool isValidBST(TreeNode * root)
		{
			if(root == NULL)
				return true;
			return dfs(root,INT_MIN,INT_MAX);
		}
		bool dfs(TreeNode * root,int MIN,int MAX)
		{
			if(root == NULL)
				return true;
			else if(root->val <= MIN || root->val >= MAX)
				return false;
			else
				return dfs(root->left,MIN,root->val) && dfs(root->right,root->val,MAX);
		}
};

int main()
{
	Solution sol;
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->right = new TreeNode(6);
	root->right = new TreeNode(15);
	root->right->right = new TreeNode(20);
	cout << sol.isValidBST(root) << endl;
	return 0;
}



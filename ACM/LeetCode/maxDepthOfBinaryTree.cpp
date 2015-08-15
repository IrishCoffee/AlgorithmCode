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
		int maxDepth(TreeNode * root)
		{
			if(root == NULL) return 0;
			int ans = -1;
			dfs(root,ans,1);
			return ans;
		}
		void dfs(TreeNode * root,int & ans,int depth)
		{
			if(root->left == NULL && root->right == NULL) // leaf node
			{
				ans = max(ans,depth);
				return;
			}
			if(root->left)
				dfs(root->left,ans,depth+1);
			if(root->right)
				dfs(root->right,ans,depth+1);
			return;
		}
};

int main()
{
	Solution sol;
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(9);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(5);
	root->right->left->left = new TreeNode(6);
	root->right->left->right = new TreeNode(7);
	root->right->left->right->left = new TreeNode(8);
	cout << sol.maxDepth(root) << endl;
	return 0;
}

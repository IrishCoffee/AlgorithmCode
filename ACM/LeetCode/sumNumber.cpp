#include <iostream>
#include <cstdio>
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
		int sumNumbers(TreeNode * root)
		{
			if(root == NULL) return 0;
			int sum = 0;
			int val = 0;
			dfs(root,sum,val);
			return sum;
		}
		void dfs(TreeNode * root,int &sum,int val)
		{
			val += root->val;
			if(root->left == NULL && root->right == NULL) // leaf node
				sum += val;
			if(root->left != NULL)
				dfs(root->left,sum,val*10);
			if(root->right != NULL)
				dfs(root->right,sum,val*10);
			val -= root->val;
			return;
		}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution sol;
	cout << sol.sumNumbers(root) <<endl;
	return 0;
}

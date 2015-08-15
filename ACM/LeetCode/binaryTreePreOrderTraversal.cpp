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
		vector<int> preorderTraversal(TreeNode * root)
		{
			vector<int> v;
			dfs(v,root);
			return v;
		}
		void dfs(vector<int> &v,TreeNode * root)
		{
			if(root == NULL)
				return;
			if(root != NULL)
				v.push_back(root->val);
			if(root->left != NULL)
				dfs(v,root->left);
			if(root->right != NULL)
				dfs(v,root->right);
			return;
		}
};

int main()
{
	Solution sol;
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(5);
	root->right->left->left = new TreeNode(6);
	root->right->left->right = new TreeNode(7);
	root->right->left->right->left = new TreeNode(8);
	vector<int> v = sol.preorderTraversal(root);
	for(int i = 0; i < v.size(); ++i)
		cout << (char)('A' + (int)(v[i] - 1)) << " ";
	cout << endl;
	return 0;
}

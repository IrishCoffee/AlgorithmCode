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
			vector<int> v;
			dfs(v,root);
			int size = v.size();
			for(int i = 1; i < size;++i)
				if(v[i] <= v[i-1])
					return false;
			return true;
		}
		void dfs(vector<int> &v,TreeNode * root)
		{
			if(root->left)
				dfs(v,root->left);
			v.push_back(root->val);
			if(root->right)
				dfs(v,root->right);
		}
};

int main()
{
	Solution sol;
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(5);
	root->left->right = new TreeNode(6);
	root->right = new TreeNode(15);
	root->right->right = new TreeNode(20);
	cout << sol.isValidBST(root) << endl;
	return 0;
}



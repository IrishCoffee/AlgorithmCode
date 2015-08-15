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
		vector<vector<int> > pathSum(TreeNode *root,int sum)
		{
			vector<vector<int> > v;
			vector<int> vv;
			if(root == NULL) return v;
			int val = 0;
			dfs(root,sum,v,vv,val);
			return v;
		}
		void dfs(TreeNode *root,int sum,vector<vector<int> > &v,vector<int> &vv,int &val)
		{
			val += root->val;
			vv.push_back(root->val);
			if(root->left == NULL && root->right == NULL) // leaf node
			{
				if(val == sum)
					v.push_back(vv);
			}
			if(root->left != NULL)
				dfs(root->left,sum,v,vv,val);
			if(root->right != NULL)
				dfs(root->right,sum,v,vv,val);
			val -= root->val;
			vv.pop_back();
			return;
		}
			
};

int main()
{
	Solution sol;
	TreeNode * root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);
	vector<vector<int> > v = sol.pathSum(root,22);
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
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
		vector<vector<int> > levelOrder(TreeNode * root)
		{
			vector<vector<int> > v;
			if(root == NULL) return v;
			queue<TreeNode *> q[2];
			q[0].push(root);
			int i = 0;
			while(!q[i].empty())
			{
				vector<int> vv;
				int j = (i+1) % 2;
				while(!q[i].empty())
				{
					TreeNode * tmp = q[i].front();
					q[i].pop();
					vv.push_back(tmp->val);
					if(tmp->left != NULL)
						q[j].push(tmp->left);
					if(tmp->right != NULL)
						q[j].push(tmp->right);
				}
				i = j;
				v.push_back(vv);
			}
			return v;
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
	vector<vector<int> > v = sol.levelOrder(root);
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}

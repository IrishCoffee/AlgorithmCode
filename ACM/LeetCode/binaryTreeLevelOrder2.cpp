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
		vector<vector<int> > levelOrderBottom(TreeNode * root)
		{
			queue<TreeNode *> q[2];
			vector<vector<int> > v;
			if(root == NULL)
				return v;
			int i = 0;
			q[0].push(root);
			while(true)
			{
				if(q[i].empty())
					break;
				int j = (i + 1) % 2;
				vector<int> vv;
				while(!q[i].empty())
				{
					TreeNode * tmp = q[i].front();
					q[i].pop();
						vv.push_back(tmp->val);
					if(tmp->left)
						q[j].push(tmp->left);
					if(tmp->right)
						q[j].push(tmp->right);
				}
				v.insert(v.begin(),vv);
				i = j;
			}
			return v;
		}
};

int main()
{
	Solution sol;
	TreeNode * root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	vector<vector<int> > v = sol.levelOrderBottom(root);
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}

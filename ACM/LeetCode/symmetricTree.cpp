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
		bool isSymmetric(TreeNode * root)
		{
			if(root == NULL) return true;
			queue<TreeNode *> q[2];
			q[0].push(root);
			for(int i = 0;;)
			{
				if(q[i].empty())
					return true;
				vector<int> v;
				int j = (i+1) % 2;
				while(!q[i].empty())
				{
					TreeNode * tmp = q[i].front();
					q[i].pop();
					if(tmp->left == NULL)
						v.push_back(0);
					else
					{
						q[j].push(tmp->left);
						v.push_back(tmp->left->val);
					}
					if(tmp->right == NULL)
						v.push_back(0);
					else
					{
						q[j].push(tmp->right);
						v.push_back(tmp->right->val);
					}
				}
				int len = v.size();
				for(int k = 0; k < len/2; ++k)
					if(v[k] != v[len - 1 - k])
						return false;
				i = j;
			}
		}
};

int main()
{
	Solution sol;
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
//	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(2);
//	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(4);
	cout << sol.isSymmetric(root) << endl;
	return 0;
}

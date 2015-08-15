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
		int minDepth(TreeNode * root)
		{
			if(root == NULL) return 0;
			queue<TreeNode *> q[2];
			q[0].push(root);
			int depth = 1;
			for(int i = 0;;)
			{
				int j = (i+1) % 2;
				while(!q[i].empty())
				{
					TreeNode * tmp = q[i].front();
					q[i].pop();
					if(tmp->left == NULL && tmp->right == NULL)
						return depth;
					if(tmp->left != NULL)
						q[j].push(tmp->left);
					if(tmp->right != NULL)
						q[j].push(tmp->right);
				}
				i = j;
				depth++;
			}
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
	cout << sol.minDepth(root) << endl;
	return 0;
}

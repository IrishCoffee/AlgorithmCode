#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode * left;
	TreeLinkNode * right;
	TreeLinkNode * next;
	TreeLinkNode(int x): val(x),left(NULL),right(NULL),next(NULL) {}
};

class Solution
{
	public:
		void connect(TreeLinkNode * root)
		{
			queue<TreeLinkNode *> q[2];
			if(root == NULL)
				return;
			q[0].push(root);
			int i = 0;
			TreeLinkNode * prev = NULL;
			while(!q[i].empty())
			{
				int j = i ^ 1;
				while(!q[i].empty())
				{
					TreeLinkNode * tmp = q[i].front();
					q[i].pop();
					if(tmp->left)
						q[j].push(tmp->left);
					if(tmp->right)
						q[j].push(tmp->right);
					if(!prev)
						prev = tmp;
					else
					{
						prev->next = tmp;
						prev = tmp;
					}
				}
				i = j;
				prev = NULL;
			}
			return;
		}
};
int main()
{
	Solution sol;
	TreeLinkNode * root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->right = new TreeLinkNode(7);
	sol.connect(root);
	cout << root->left->right->next->val << endl;
	return 0;
}

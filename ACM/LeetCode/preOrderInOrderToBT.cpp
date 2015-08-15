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
		TreeNode * buildTree(vector<int> &preorder,vector<int> &inorder)
		{
			int size = preorder.size();
			if(size == 0)
				return NULL;
			return build(preorder,inorder,0,size-1,0,size-1);
		}
		TreeNode * build(vector<int> &preorder,vector<int> &inorder,int s1,int e1,int s2,int e2)
		{
			int root_num = preorder[s1];
			int index;
			for(int i = s2; i <= e2; ++i)
			{
				if(inorder[i] == root_num)
				{
					index = i;
					break;
				}
			}
			TreeNode * root = new TreeNode(root_num);
			if(index != s2)
				root->left = build(preorder,inorder,s1 + 1,s1 + index - s2,s2,index-1);
			if(index != e2)
				root->right = build(preorder,inorder,s1 + index - s2 +1,e1,index+1,e2);
			return root;
		}
};

int main()
{
	Solution sol;
	int pre[10] = {4,1,0,2,3,7,5,6,8,9};
	int in[10] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> preorder;
	vector<int> inorder;
	for(int i = 0; i < 10; ++i)
	{
		preorder.push_back(pre[i]);
		inorder.push_back(in[i]);
	}
	TreeNode * root = sol.buildTree(preorder,inorder);
	cout << root->val << endl;
	cout << root->left->val << endl;
	cout << root->right->val << endl;
	cout << root->right->right->val << endl;
	return 0;
}
				

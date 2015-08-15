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
		TreeNode * buildTree(vector<int> &inorder,vector<int> &postorder)
		{
			int size = inorder.size();
			if(size == 0)
				return NULL;
			return build(postorder,inorder,0,size-1,0,size-1);
		}
		TreeNode * build(vector<int> &postorder,vector<int> &inorder,int s1,int e1,int s2,int e2)
		{
			int root_num = postorder[e1];
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
				root->left = build(postorder,inorder,s1,s1 + (index - 1 - s2),s2,index-1);
			if(index != e2)
				root->right = build(postorder,inorder,s1 + index - s2,e1-1,index+1,e2);
			return root;
		}
};

int main()
{
	Solution sol;
	int post[10] = {0,3,2,1,6,5,9,8,7,4};
	int in[10] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> postorder;
	vector<int> inorder;
	for(int i = 0; i < 10; ++i)
	{
		postorder.push_back(post[i]);
		inorder.push_back(in[i]);
	}
	TreeNode * root = sol.buildTree(inorder,postorder);
	cout << root->val << endl;
	cout << root->left->val << endl;
	cout << root->right->val << endl;
	cout << root->right->right->val << endl;
	return 0;
}
				

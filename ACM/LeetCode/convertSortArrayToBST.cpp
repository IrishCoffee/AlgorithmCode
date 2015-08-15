#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

class Solution
{
	public:
		TreeNode *sortedArrayToBST(vector<int> &num)
		{
			int size = num.size();
			if(size == 0)
				return NULL;
			TreeNode * root = build(0,size-1,num);
			return root;
		}
		TreeNode * build(int left,int right,vector<int> &num)
		{
			if(left > right)
				return NULL;
			int mid = (left + right) / 2;
			TreeNode *root = new TreeNode(num[mid]);
			root->left = build(left,mid-1,num);
			root->right = build(mid+1,right,num);
			return root;
		}
};

int main()
{
	Solution sol;
	vector<int> num;
	for(int i = 0; i < 8;++i)
		num.push_back(i);
	TreeNode *root = sol.sortedArrayToBST(num);
	cout << root->val << endl;
	cout << root->left->val << endl;
	cout << root->right->val << endl;
	cout << root->left->left->val << endl;
	cout << root->left->right->val << endl;
	cout << root->right->left->val << endl;
	cout << root->right->right->val << endl;
	cout << root->right->right->right->val << endl;
	return 0;
}


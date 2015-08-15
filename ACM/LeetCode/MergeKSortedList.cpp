#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

struct NODE
{
	int val,id;
	friend bool operator< (NODE n1,NODE n2)
	{
		return n1.val > n2.val;
	}
};
class Solution
{
	public:
		ListNode *mergeKLists(vector<ListNode *> &lists)
		{
			ListNode *head = NULL, *ans = NULL;
			ListNode* p[1024];
			NODE tmp;
			int size = lists.size();
			if(size == 0)
				return ans;
			priority_queue<NODE> q;
			for(int i = 0; i < size; ++i)
			{
				if(lists[i] == NULL)
					continue;
				tmp.val = lists[i]->val;
				tmp.id = i;
				q.push(tmp);
				p[i] = lists[i];
			}
			while(!q.empty())
			{
				NODE tmp = q.top();
				q.pop();
				if(ans == NULL)
				{
					ans = new ListNode(tmp.val);
					head = ans;
				}
				else
					ans->val = tmp.val;
				ans->next = new ListNode(tmp.val);
				int id = tmp.id;
				p[id] = p[id]->next;
				if(p[id] != NULL)
				{
					tmp.val = p[id]->val;
					tmp.id = id;
					q.push(tmp);
				}
				if(q.empty())
					ans->next = NULL;
				else
					ans = ans->next;
			}
			return head;
		}
};

int main()
{
	Solution sol;
	int n[4][6] = {{2,4,6,8,10,12},{1,3,5,7,9,11},{2,4,6,8,10,12},{1,3,5,7,9,11}};
	ListNode* p[4];
	ListNode* h[4];
	for(int i = 0; i < 4; ++i)
	{
		p[i] = new ListNode(n[i][0]);
		h[i] = p[i];
		for(int j = 1; j < 6; ++j)
		{
			p[i]->next = new ListNode(n[i][j]);
			p[i] = p[i]->next;
		}
	}
	vector<ListNode*> v;
//	v.push_back(h[0]);
//	v.push_back(h[1]);
//	v.push_back(h[2]);
//	v.push_back(h[3]);
	ListNode* tmp = NULL;
	v.push_back(tmp);
	ListNode *ans = sol.mergeKLists(v);
	while(ans != NULL)
	{
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;
	return 0;
}



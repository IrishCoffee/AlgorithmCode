#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct NODE
{
	int num,pos;
};
bool cmp(const NODE &a, const NODE &b)
{
	if(a.num < b.num)
		return true;
	return false;
}
class Solution
{
	public:
		vector<int> twoSum(vector<int> &numbers,int target)
		{
			vector<int> result;
			vector<NODE> number;
			int size = numbers.size();
			for(int i = 0; i < size;++i)
			{
				NODE tmp;
				tmp.num = numbers[i];
				tmp.pos = i + 1;
				number.push_back(tmp);
			}
			sort(number.begin(),number.end(),cmp);
			int left = 0,right = size - 1;
			for(;left < size;++left)
			{
				int tmp = number[left].num + number[right].num;
				while(tmp > target)
				{
					--right;
					tmp = number[left].num + number[right].num;
				}
				if(tmp == target)
				{
					result.push_back(number[left].pos);
					result.push_back(number[right].pos);
					sort(result.begin(),result.end());
					return result;
				}
			}
		}
};

int main()
{
	freopen("in","r",stdin);
	Solution solution;
	vector<int> numbers;
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; ++i)
	{
		int num;
		scanf("%d",&num);
		cout << num << " ";
		numbers.push_back(num);
	}
	int target;
	cin >> target;
	cout << "\n" << "target " << target << endl;
	vector<int> result = solution.twoSum(numbers,target);
	printf("%d %d\n",result[0],result[1]);
	return 0;
}

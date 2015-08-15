#include <iostream>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<int> plusOne(vector<int> &digits)
		{
			int len = digits.size();
			int carry = 1;
			for(int i = len-1; i >= 0; --i)
			{
				int tmp = digits[i] + carry;
				carry = tmp / 10;
				digits[i] = tmp % 10;
			}
			if(carry > 0)
				digits.insert(digits.begin(),carry);
			return digits;
		}
};

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	Solution sol;
	v = sol.plusOne(v);
	for(int i = 0; i < v.size(); ++i)
		cout << v[i];
	cout << endl;
	return 0;
}

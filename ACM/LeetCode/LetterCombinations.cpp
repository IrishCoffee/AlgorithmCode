char symbol[10][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int size[10] = {0,0,3,3,3,3,3,4,3,4};
class Solution
{
	public:
		vector<string> letterCombinations(string digits)
		{
			vector<string> ans;
			int length = digits.size();
			if(length == 0)
			{
				string tmp = "";
				ans.push_back(tmp);
				return ans;
			}
			int num[1024];
			for(int i = 0; i < length; ++i)
				num[i] = digits[i] - '0';
			string tmp;
			f(0,length,num,tmp,ans);
			return ans;
		}
		void f(int index,int length,int num[],string tmp,vector<string> &ans)
		{
			if(size[num[index]] == 0)
				f(index+1,length,num,tmp,ans);
			for(int i = 0; i < size[num[index]]; ++i)
			{
				string new_tmp = tmp;
				new_tmp.push_back(symbol[num[index]][i]);
				if(index == length-1)
					ans.push_back(new_tmp);
				else
					f(index+1,length,num,new_tmp,ans);
			}
		}
};
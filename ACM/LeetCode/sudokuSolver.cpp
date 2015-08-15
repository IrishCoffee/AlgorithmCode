#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution
{
	public:
		void solveSudoku(vector<vector<char> > &board)
		{
			solve(board,0,0);
		}
		bool check(vector<vector<char> > &board,int r,int c)
		{
			for(int i = 0; i < 9; ++i)
				if(i != c && board[r][i] == board[r][c])
					return false;
			for(int i = 0; i < 9; ++i)
				if(i != r && board[i][c] == board[r][c])
					return false;
			int s_r = r / 3 * 3;
			int s_c = c / 3 * 3;
			for(int i = s_r; i < s_r + 3; ++i)
			{
				for(int j = s_c; j < s_c + 3; ++j)
				{
					if(i != r && j != c && board[i][j] == board[r][c])
						return false;
				}
			}
			return true;
		}
		bool solve(vector<vector<char> >&board,int r,int c)
		{
			if(c == 9)
				return solve(board,r+1,0);
			if(r == 9)
				return true;
			if(board[r][c] != '.')
				return solve(board,r,c+1);
			for(int i = 1; i <= 9; ++i)
			{
				board[r][c] = '0' + i;
				if(check(board,r,c) && solve(board,r,c+1))
					return true;
				board[r][c] = '.';
			}
			return false;
		}
};
int main()
{
	vector<vector<char> > v;
	char board[10][10] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
	for(int i = 0; i < 9; ++i)
	{
		vector<char> c;
		for(int j = 0; j < 9; ++j)
			c.push_back(board[i][j]);
		v.push_back(c);
	}
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
			printf("%-2c",v[i][j]);
		printf("\n");
	}
	printf("\n");
	Solution sol;
	sol.solveSudoku(v);
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
			printf("%-2c",v[i][j]);
		printf("\n");
	}
	return 0;
}


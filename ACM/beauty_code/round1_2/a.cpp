#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <iterator>
using namespace std;
int main()
{
	int T;
	char input1[10009];
	char input2[10009];
	int id1[10009];
	int id2[10009];
	scanf("%d",&T);
	int nn = 0;
	while(T--)
	{
		int L;
		scanf("%d",&L);
		scanf("%s%s",input1,input2);
		int len1 = strlen(input1);
		int len2 = strlen(input2);
		int num = 0;
		for(int i = 0; i < len1; i += 2)
			num += input1[i] - '0';
		num /= L;
		id1[0] = 0,id2[0] = 0;
		for(int i = 2; i < len1; i += 2)
			id1[i] = id1[i-2] + input1[i-2] - '0';
		for(int i = 2; i < len2; i += 2)
			id2[i] = id2[i-2] + input2[i-2] - '0';
		map<string,int> m;
		m.clear();
		for(int i = 0; i < num; ++i)
		{
			string s;
			int id = i;
			int tmp = L;
			while(tmp--)
			{
				for(int j = 0; j < len1; j += 2)
				{
					if(id >= id1[j])
					{
						if(j == len1-2 || (j < len1-2 && id < id1[j+2]))
						{
							s+= input1[j+1];
							break;
						}
					}
				}
				id += num;
			}
			m[s]++;
		}
		bool flag = true;
		map<string,int>::iterator l_it;
		for(int i = 0; i < num; ++i)
		{
			string s;
			int id = i;
			int tmp = L;
			while(tmp--)
			{
				for(int j = 0; j < len2; j += 2)
				{
					if(id >= id2[j])
					{
						if(j == len2-2 || (j < len2-2 && id < id2[j+2]))
						{
							s+= input2[j+1];
							break;
						}
					}
				}
				id += num;
			}
			//	cout << s << " " << m[s] << endl;
			l_it = m.find(s);
			if(l_it != m.end())
			{
				m[s]--;
				if(m[s] == 0)
					m.erase(l_it);
			}
			else
			{
				flag = false;
				break;
			}
		}
		printf("Case %d: ",++nn);
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

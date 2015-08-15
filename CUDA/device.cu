#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	cudaDeviceProp prop;
	int count;
	cudaGetDeviceCount(&count);
	cout << count << endl;
	for(int i = 0; i < count;++i)
	{
		cudaGetDeviceProperties(&prop,i);
		printf("Name: %s\n",prop.name);
		printf("Cumpute capability: %d.%d\n",prop.major,prop.minor);
		printf("\n");
	}
}


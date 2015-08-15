#include <stdio.h>
#include <cuda_runtime.h>

#define ARRAY_SIZE 8
#define BLOCK_SIZE 16

__global__ void preSum(int *g_num, int *ans,int size)
{
	int tx = threadIdx.x;
	int pOut = 0,pIn = 1;
	__shared__ int s_num[2][BLOCK_SIZE];
	
	s_num[0][tx] = g_num[tx];
	s_num[1][tx] = s_num[0][tx];

	__syncthreads();

	for(int offset = 1; offset < size; offset *= 2)
	{
		pOut = 1 - pOut;
		pIn = 1 - pOut;
		if(tx >= offset)
			s_num[pOut][tx] = s_num[pIn][tx] + s_num[pIn][tx - offset];
		else
			s_num[pOut][tx] = s_num[pIn][tx];
		__syncthreads();
	}
	ans[tx] = s_num[pOut][tx];
}

int main()
{
	int num[8] = {3,1,7,0,4,1,6,3};
	int *h_num = (int*)malloc(ARRAY_SIZE);
	int *h_ans = (int*)malloc(ARRAY_SIZE);
	int *d_num, *d_ans;
	cudaMalloc((void **)&d_num,sizeof(int) * ARRAY_SIZE);
	cudaMalloc((void **)&d_ans,sizeof(int) * ARRAY_SIZE);
	
	for(int i = 0; i < ARRAY_SIZE; ++i)
		h_num[i] = num[i];
		printf("%d\n",h_num[i]);

	cudaMemcpy(d_num,h_num,sizeof(int) * ARRAY_SIZE,cudaMemcpyHostToDevice);
	
	preSum<<<1,BLOCK_SIZE>>>(d_num,d_ans,ARRAY_SIZE);
	
	cudaMemcpy(h_ans,d_ans,sizeof(int) * ARRAY_SIZE,cudaMemcpyDeviceToHost);

	for(int i = 0; i < ARRAY_SIZE; ++i)
		printf("i %d %d\n",i,h_ans[i]);
	printf("\n");

//	free(h_num);
//	free(h_ans);
//	cudaFree(d_num);
//	cudaFree(d_ans);
	return 0;
}


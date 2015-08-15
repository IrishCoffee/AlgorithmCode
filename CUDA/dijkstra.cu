#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define N 1024
#define INF 0x03F3F3F
int map[N * N];
int path[N];

__global__ void kernel1(int *nv,int *map,int *cost,int *tmp_cost,bool *visited,int * tmp_path)
{
	const int nn = 1024;
	int tid = threadIdx.x + blockIdx.x * blockDim.x;
	//fetch all its neighbour
	if(visited[tid])
	{
		visited[tid] = false;
		for(int i = 0; i < *nv; ++i)
		{
			if(cost[tid] + map[tid * nn + i] < tmp_cost[i])
			{
				tmp_path[i] = tid;
				tmp_cost[i] = cost[tid] + map[tid * N + i];
			}
		}
	}
	return;
}
__global__ void kernel2(int *cost,int *tmp_cost,bool *visited,bool *flag,int *tmp_path,int *path)
{
	int tid = threadIdx.x + blockIdx.x * blockDim.x;
	//some vertex can be updated,means that it is the new one to the queue
	if(cost[tid] > tmp_cost[tid])
	{
		path[tid] = tmp_path[tid];
		visited[tid] = true;
		cost[tid] = tmp_cost[tid];
		*flag = true;
	}
	tmp_cost[tid] = cost[tid];//if cost[tid] <= tmp_cost[tid]
	tmp_path[tid] = path[tid];
	return;
}
void print_path(int node,int path[])
{
	if(path[node] == -1)
	{
		printf("%d ",node + 1);
		return;
	}
	else
	{
		print_path(path[node],path);
		printf("%d ",node + 1);
	}
	return;
}

int main()
{
	freopen("input_dijkstra","r",stdin);
	int cost[N],tmp_cost[N],path[N],tmp_path[N];
	bool visited[N],flag;

	int *dev_cost,*dev_tmp_cost,*dev_map,*dev_nv,*dev_path,*dev_tmp_path;
	bool *dev_visited,*dev_flag;

	int nv,ne;
	scanf("%d%d",&nv,&ne);
	//initialize
	for(int i = 0; i < nv; ++i)
	{
		cost[i] = INF;
		tmp_cost[i] = INF;
		visited[i] = false;
		for(int j = 0; j < nv; ++j)
			map[i * N + j] = map[j * N + i] = INF;
	}
	//read all the edges
	for(int i = 0; i < ne; ++i)
	{
		int p,q,w;
		scanf("%d%d%d",&p,&q,&w);
		map[p * N + q] = map[q * N + p] = w;
	}

	int source;
	scanf("%d",&source);
	cost[source] = tmp_cost[source] = 0;
	visited[source] = true;
	flag = true;
	path[source] = -1;
	tmp_path[source] = -1;

	cout<<0<<endl;
	cudaMalloc((void**)&dev_cost,N * sizeof(int));
	cout<<1<<endl;
	cudaMalloc((void**)&dev_tmp_cost,N * sizeof(int));
	cudaMalloc((void**)&dev_visited,N * sizeof(bool));
	cudaMalloc((void**)&dev_map,N * N * sizeof(int));
	cudaMalloc((void**)&dev_flag,sizeof(bool));
	cudaMalloc((void**)&dev_nv,sizeof(int));
	cudaMalloc((void**)&dev_path,N * sizeof(int));
	cudaMalloc((void**)&dev_tmp_path,N * sizeof(int));

	cudaMemcpy(dev_cost,cost,N * sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(dev_tmp_cost,tmp_cost,N * sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(dev_visited,visited,N * sizeof(bool),cudaMemcpyHostToDevice);
	cudaMemcpy(dev_map,map,N * N * sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(dev_flag,&flag,sizeof(bool),cudaMemcpyHostToDevice);
	cudaMemcpy(dev_nv,&nv,sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(dev_path,path,N*sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(dev_tmp_path,tmp_path,N*sizeof(int),cudaMemcpyHostToDevice);

	while(flag)
	{
		flag = false;
		kernel1<<<1,nv>>>(dev_nv,dev_map,dev_cost,dev_tmp_cost,dev_visited,dev_tmp_path);
		cudaMemcpy(dev_flag,&flag,sizeof(bool),cudaMemcpyHostToDevice);
		kernel2<<<1,nv>>>(dev_cost,dev_tmp_cost,dev_visited,dev_flag,dev_tmp_path,dev_path);
		cudaMemcpy(&flag,dev_flag,sizeof(bool),cudaMemcpyDeviceToHost);
	}
	cudaMemcpy(cost,dev_cost,N*sizeof(int),cudaMemcpyDeviceToHost);
	cudaMemcpy(path,dev_path,N*sizeof(int),cudaMemcpyDeviceToHost);
	for(int i = 0; i < nv; ++i)
	{
		printf("Node %d cost = %2d  path: ",i+1,cost[i]);
		print_path(i,path);
		printf("\n");
	}
	cout << endl;
	return 0;
}




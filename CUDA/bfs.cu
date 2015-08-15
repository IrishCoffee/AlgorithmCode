#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define V 1024
#define E 1024
struct NODE
{
	int begin;
	int end;
}node[V];
__global__ void bfs(NODE * node,int * edge,int * cost,bool * frontier,bool * visited)
{
	int tid = threadIdx.x + blockIdx.x * blockDim.x;
	if(frontier[tid])
	{
		frontier[tid] = false;
		visited[tid] = true;
		for(int i = node[tid].begin; i < node[tid].end; ++i)
		{
			if(!visited[edge[i]])
			{
				cost[edge[i]] = cost[tid] + 1;
				frontier[edge[i]] = true;
			}
		}
	}
	return;
}
int main()
{
	freopen("input_bfs","r",stdin);
	int nv,ne;
	scanf("%d%d",&nv,&ne);

	int edge[2*E],cost[V];
	bool frontier[V],visited[V];

	int *dev_edge,*dev_cost;
	bool *dev_frontier,*dev_visited;
	NODE *dev_node;
	memset(cost,-1,nv * sizeof(int));
	memset(frontier,false,nv * sizeof(bool));
	memset(visited,false,nv * sizeof(bool));

	for(int i = 0; i < nv;++i)
	{
		int edge_num;
		scanf("%d",&edge_num);
		if(i == 0)
			node[i].begin = 0;
		else
			node[i].begin = node[i-1].end;
		node[i].end = node[i].begin;
		//read edges of this vertex
		for(int j = 0; j < edge_num; ++j)
		{
			int vertex;
			scanf("%d",&vertex);
			edge[node[i].begin + j] = vertex;
			node[i].end++;
		}
	}
	for(int i = 0; i < 2*ne; ++i)
		cout << edge[i] << " ";
	cout << endl;

	cudaMalloc((void**)&dev_edge,2*ne*sizeof(int));
	cudaMalloc((void**)&dev_cost,nv*sizeof(int));
	cudaMalloc((void**)&dev_frontier,nv*sizeof(bool));
	cudaMalloc((void**)&dev_visited,nv*sizeof(bool));
	cudaMalloc((void**)&dev_node,nv*sizeof(NODE));

	cudaMemcpy(dev_edge,edge,2*ne*sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(dev_visited,visited,nv*sizeof(bool),cudaMemcpyHostToDevice);
	cudaMemcpy(dev_node,node,nv*sizeof(NODE),cudaMemcpyHostToDevice);

	int source;
	scanf("%d",&source);
	frontier[source] = true;
	cost[source] = 0;
	cudaMemcpy(dev_cost,cost,nv*sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(dev_frontier,frontier,nv*sizeof(bool),cudaMemcpyHostToDevice);
	bool flag = true;
	while(flag)
	{
		flag = false;
		for(int i = 0; i < nv;++i)
		{
			if(frontier[i])
			{
				cout << "frontier " << i << endl;
				flag = true;
				bfs<<<1,nv>>>(dev_node,dev_edge,dev_cost,dev_frontier,dev_visited);
				cudaMemcpy(frontier,dev_frontier,nv*sizeof(bool),cudaMemcpyDeviceToHost);
				break;
			}
		}
	}
	cudaMemcpy(cost,dev_cost,nv*sizeof(int),cudaMemcpyDeviceToHost);
	for(int i = 0; i < nv; ++i)
		printf("%d %d\n",i,cost[i]);
	return 0;
}







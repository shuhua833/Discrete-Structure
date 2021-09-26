//Minimum spanning tree
#include<stdio.h>
int i,j,k,a,b,u,v,n,e=1;
int Min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
int main()
{
	printf("\t\tImplementation of Kruskal's Algorithm\n\n");
	printf("Enter the no. of vertices:");
	scanf("%d",&n);
	printf("Enter the cost of adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			cost[i][j]=999;
		}
	}
	printf("The edges of minimum cost spanning tree are:");
	while(e<n)
	{
		for(i=1,Min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<Min)
				{
					Min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d)=%d)\n",e,a,b,Min);
			mincost+=Min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\nminimum cost:",mincost);
}

int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}

int uni(int i,int j)
{
	if(i!=j)
	{
		parent [j]=i;
		return 1;
		
		}
		return 0;
	}

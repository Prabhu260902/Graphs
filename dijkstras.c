#include<stdio.h>
#include<stdlib.h>
int main()
{
	int adj[30][30],n,vis[30],par[30],dist[30],s,d,c=1,v,min;
	printf("enter no.of verteies");
	scanf("%d",&n);
	printf("\nenter adj matrix");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&adj[i][j]);
			if(adj[i][j]==0)
				adj[i][j]=999;
		}
	}
	printf("\nenter source node");
	scanf("%d",&s);
	printf("\nenter destination node");
	scanf("%d",&d);
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		dist[i]=adj[s][i];
		par[i]=-1;
	}

	
	vis[s]=1;
	dist[s]=0;
	
	while(c<=n){
		min=999;
		for(int i=1;i<=n;i++)
		{
			if(dist[i]<min && vis[i]==0)
			{
				min=dist[i];
				v=i;
			}
		}
		vis[v]=1;
		c++;
		for(int i=1;i<=n;i++)
		{
			if(dist[i]>dist[v]+adj[v][i]){
				dist[i]=dist[v]+adj[v][i];
				par[i]=v;
			}
		}
	}
	printf("\n\n");
	printf("%d\n",dist[d]);
	while(d!=-1)
	{
		printf("%d",d);
		d=par[d];
	}
	printf("%d",s);
}

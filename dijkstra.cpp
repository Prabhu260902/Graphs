#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void bfs(vector<pair<int,int>>adj[],vector<int>&v,int n)
{
	queue<int>q;
	q.push(1);
	for(int i=2;i<=n;i++)
	{
		while(q.size()!=0)
		{
			int a=q.front();
			q.pop();
			for(auto it:adj[a])
			{
				if(v[a]+it.second<=v[it.first])
				{ 
					q.push(it.first);
					v[it.first]=v[a]+it.second;
				}
			}
			
		}
	}
	for(int i=1;i<=n;i++) cout<<v[i]<<" ";
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>adj[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v,d;
		cin>>u>>v>>d;
		adj[u].push_back({v,d});
		adj[v].push_back({u,d});
	}


	//BFS
	vector<int>vis(n+1,INT_MAX);
	vis[1]=0;
	bfs(adj,vis,n);



}
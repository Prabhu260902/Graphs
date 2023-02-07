#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void bfs(vector<pair<int,int>>adj[],vector<int>&v,int n)
{
	priority_queue < pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > q;
	int ans=0;
	vector<int>par(n,-1);
	vector<int>dis(n,INT_MAX);
	q.push({0,0});
	par[0]=0;
	dis[0]=0;
	v[0]=1;
	while(q.size()!=0)
	{
		pair<int,int> a=q.top();
		q.pop();
		if(!v[a.second]) v[a.second]=1;
		for(auto it:adj[a.second])
		{
			if(!v[it.first] and dis[it.first]>it.second and par[a.second]!=it.first)
			{ 
				q.push({it.second,it.first});
				dis[it.first]=it.second;
				par[it.first]=a.second;
			}			
		}
	}
	ans=0;
	for(int i=0;i<dis.size();i++) 
	{
		ans+=dis[i];
		cout<<par[i]<<" "<<i<<" "<<dis[i]<<endl;
	}
	cout<<ans<<endl;
	
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>adj[n];
	for(int i=0;i<m;i++)
	{
		int u,v,d;
		cin>>u>>v>>d;
		adj[u].push_back({v,d});
		adj[v].push_back({u,d});
	}


	//BFS
	vector<int>vis(n,0);
	bfs(adj,vis,n);



}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dfs(vector<int>adj[],vector<int>&v,int parent,int child)
{
	v[child]=1;
	for(auto it:adj[child])
	{
		if(!v[it]) 
		{
				if(dfs(adj,v,child,it)) return true;
		}
		else if(it!=parent) return true;
		
	}
	return false;
}

bool bfs(vector<int>adj[],vector<int>&v,int n)
{
	queue<pair<int,int>>q;
	for(int i=1;i<=n;i++)
	{
		if(!v[i]){
			q.push({i,-1});
			v[i]=1;
		}
		while(q.size()!=0)
		{
			pair<int,int> a=q.front();
			q.pop();
			for(auto it:adj[a.first])
			{
				if(!v[it]) q.push({it,a.first});
				else if(a.second!=it) return true;
				v[it]=1;
			}
			
		}
	}
	return false;
}
int main()
{
	int n,m;
	cin>>n>>m;

	// adj list
	// to take input
	vector<int>adj[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//DFS
	bool f=true;
	vector<int>v(n+1,0);

	for(int i=1;i<=n;i++)
	{
		if(v[i]!=1)
		{
			if(dfs(adj,v,-1,i))
			{
				cout<<"Cycle\n";
				f=false;
			}
		} 
	}
	if(f) cout<<"NO Cycle\n";


	//BFS
	vector<int>vis(n+1,0);
	if(bfs(adj,vis,n)) cout<<"Cycle\n";
	else cout<<"NO Cycle\n";



}
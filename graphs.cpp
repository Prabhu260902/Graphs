#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(vector<int>adj[],vector<int>&v,int parent,int child,string ans)
{
	//v[child]=1;
	//if(child==3) cout<<ans<<endl;
	cout<<parent<<" "<<child<<endl;
	for(auto it:adj[child])
	{
		// if(v[it]!=1) 
		 dfs(adj,v,child,it,ans+to_string(it)+"--->");
	}
}

void bfs(vector<int>adj[],vector<int>&v,int n)
{
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(!v[i]){
			q.push(i);
			v[i]=1;
		}
		while(q.size()!=0)
		{
			int a=q.front();
			q.pop();
			cout<<a<<" ";
			for(auto it:adj[a])
			{
				if(!v[it]) q.push(it);
				v[it]=1;
			}
			
		}
	}
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
		//adj[v].push_back(u);
	}

	//DFS
	vector<int>v(n+1,0);
	dfs(adj,v,-1,0,"");
	// for(int i=1;i<=n;i++)
	// {
	// 	if(v[i]!=1) dfs(adj,v,-1,i,"");
	// }


	//BFS
	vector<int>vis(n+1,0);
	//bfs(adj,vis,n);



}
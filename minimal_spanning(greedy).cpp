#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,m,i,j;
	cin>>n>>m;
	vector<pair<int,int>>adj[n+1];
	for(i=0;i<m;i++)
	{
	    int u,v,w;
	    adj[u].push_back({w,v});
	    adj[v].push_back({w,u});
	}
	vector<int>key(n+1,INT_MAX);
	vector<int>mst(n+1,0);
	vector<int>parent(n+1,-1);
	key[1]=0;
//	mst[1]=true;
	for(i=1;i<=n;i++)
	{
	    int min=INT_MAX,node;
	    for(j=1;j<=n;j++)
	    {
	        cout<<mst[j];
	        if(mst[j]==0 and key[j]<min)
	        {
	            min=key[j];
	            node=j;
	        }
	    }
	    mst[node]=1;
	    for(auto it:adj[node])
	    {
	        if(key[it.second]>it.first and mst[it.second]!=1)
	        {
	            key[it.second]=it.first;
	            parent[it.second]=node;
	        }
	    }
	}
	for(i=1;i<=n;i++)
	cout<<i<<" "<<parent[i]<<endl;
	
	
	return 0;
}
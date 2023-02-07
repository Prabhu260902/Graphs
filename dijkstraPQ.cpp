//Dijkstra's shortest path algorithm
//to find the shortest path from source node to every other node 
//priroity queue




#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m; cin>>n>>m;
	vector<pair<int,int>>adj[n]; // to store edges and weights
	for(int i=0;i<m;i++){
		int w,u,v; cin>>w>>u>>v;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	int s; cin>>s;
	vector<int>parent(n,-1);
	vector<int>dist(n,INT_MAX);
	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
	q.push({0,s,-1});
	dist[s]=0;
	while(!q.empty())
	{
		int dis=q.top()[0];
		int node=q.top()[1];
		int par=q.top()[2];
		q.pop();
		for(auto i:adj[node]){
			if(dis+i.second<dist[i.first]){
				dist[i.first]=dis+i.second;
				q.push({dis+i.second,i.first,node});
				parent[i.first]=node;
			}
		}
	}


	for(auto i:dist) cout<<i<<" ";
		cout<<endl;
	int x=8;
	while(x!=-1){
		cout<<x<<"---->";
		x=parent[x];
	}

}
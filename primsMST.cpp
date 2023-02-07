//Minimum spanning tree using prims algorithm
//------Prims algorithm-------
//1.Initially select one node
//2.select one node with minimum edge conneted to the selected vertices
//3.repect untill n-1 egdes come





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
	int cst=0; // cost of minimum spanning tree
	vector<int>vis(n,0); //visited vector
	vector<pair<int,int>>mst; //mst tree
	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
	q.push({0,0,-1});
	while(!q.empty()){
		vector<int>node=q.top();
		q.pop();
		int wt=node[0];
		int u=node[1];
		int v=node[2];
		if(!vis[u]){
			vis[u]=1;
			cst+=wt;
			if(v!=-1) mst.push_back({u,v});
			for(auto it:adj[u]) if(!vis[it.first]) q.push({it.second,it.first,u});
		}
	}

	cout<<cst<<endl;
	for(auto i:mst) cout<<i.first<<" "<<i.second<<endl;
}	
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[8];
void print(vector<int>&v){
	for(auto i:v) cout<<i+1<<" ";
	cout<<endl;
}
bool valid(int ind,int x){
	for(auto i:adj[ind]) if(i==x) return false;
	return true;
}
void solve(vector<int>&vis,int val,int store)
{
	if(val==8){
		print(vis);
		return;
	}
	for(int i=0;i<8;i++){
		if(vis[i]==-1){
			if(valid(store,i)){
				vis[i]=val;
				solve(vis,val+1,i);
				vis[i]=-1;
			}
		}
	}
}
int main(){
	int n,m; cin>>n>>m;
	vector<int>vis(n,-1);
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<8;i++){
		vis[i]=0;
		solve(vis,1,i);
		vis[i]=-1;
	}
}
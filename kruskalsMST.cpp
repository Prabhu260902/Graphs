#include<bits/stdc++.h>
using namespace std;
int find(int x,vector<int>&parent){
	if(parent[x]==x) return x;
	return parent[x]=find(parent[x],parent);
}

void unionf(int a,int b,vector<int>&parent,vector<int>&rank){
	a=find(a,parent);
	b=find(b,parent);
	if(a!=b){
		if(rank[a]<rank[b]) parent[a]=b;
		if(rank[b]<rank[a]) parent[b]=a;
		if(rank[a]==rank[b]){
			parent[a]=b;
			rank[b]++;
		}
	}
}


int main(){
	int n,m; cin>>n>>m;
	vector<int>parent(n,0),rank(n,0);
	multimap<int,pair<int,int>>mp;
	for(int i=0;i<n;i++) parent[i]=i;
	for(int i=0;i<m;i++){
		int w,u,v; cin>>w>>u>>v;
		//cout<<w<<u<<v<<endl;
		mp.insert({w,{u,v}});
	}

	int cst=0;
	vector<pair<int,int>>v;
	multimap<int,pair<int,int>>::iterator i;
	for(i=mp.begin();i!=mp.end();i++){
		if(find(i->second.first,parent)!=find(i->second.second,parent)){
			cst+=i->first;
			v.push_back(i->second);
			unionf(i->second.first,i->second.second,parent,rank);
		}
	}


	cout<<cst<<endl;
	for(auto i:v) cout<<i.first<<" "<<i.second<<endl;
}
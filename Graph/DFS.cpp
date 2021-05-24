#include<bits/stdc++.h>
using namespace std;

void dfs(int src,vector<int> adj[],vector<bool> &vis){
    cout<<src<<" ";
    vis[src]=true;
    for(int i=0;i<adj[src].size();i++){
        if(vis[adj[src][i]]==false){
            dfs(adj[src][i],adj,vis);
        }
    }
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<bool> vis(V,false);
    for(int i=0;i<V;i++){
        if(vis[i]==false){
            dfs(i,adj,vis);
        }
    }
}
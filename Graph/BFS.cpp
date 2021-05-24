#include<bits/stdc++.h>
using namespace std;


void bfs(int src,vector<int> adj[],map<int,int> &dis){
    queue<int> q;
    q.push(src);
    dis[src]=0;
    while(q.size()>0){
        int u = q.front();q.pop();
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(dis.count(v)==0){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
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

    map<int,int> dis;
    for(int i=0;i<V;i++){
        if(dis.count(i)==0){
            bfs(i,adj,dis);
        }
    }
}
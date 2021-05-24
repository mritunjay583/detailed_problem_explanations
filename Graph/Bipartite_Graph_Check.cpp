
// C++ program to find out whether a
// given graph is Bipartite or not
// https://practice.geeksforgeeks.org/problems/bipartite-graph/1#
#include<bits/stdc++.h>

using namespace std;

bool helper(int src,vector<int> adj[],int color[]){
    queue<int> q;
    q.push(src);
    color[src]=-1;
    while(q.size()>0){
        int u =q.front();q.pop();
        for(int i=0;i<adj[u].size();i++){
            if(color[adj[u][i]]!=0){
                if(color[u]==color[adj[u][i]]){
                    return false;
                }
            }else{
                q.push(adj[u][i]);
                if(color[u]==-1){
                    color[adj[u][i]]=1;
                }else{
                    color[adj[u][i]]=-1;
                }
            }
        }
    }
    return true;
}
bool isBipartite(int V,vector<int>adj[]){
    int color[V]={0};
    for(int i=0;i<V;i++){
        if(color[i]==0){
            if(helper(i,adj,color)==false){
                return false;
            }
        }
    }
    return true;
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
    isBipartite(V, adj) ? cout << "Yes" : cout << "No";
    return 0;
}
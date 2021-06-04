// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



void dfs(int u,vector<int> adj[],vector<int> &vis,stack<int> &st){
    vis[u]=true;
    for(int i=0;i<adj[u].size();i++){
        int v= adj[u][i];
        if(vis[v]==false){
            dfs(v,adj,vis,st);
        }
    }
    st.push(u);
}
void dfs2(int u,vector<int> adj[],vector<int> &vis){
    vis[u]=true;
    for(int i=0;i<adj[u].size();i++){
        int v= adj[u][i];
        if(vis[v]==false){
            dfs2(v,adj,vis);
        }
    }
}
int kosaraju(int V, vector<int> adj[])
{
    vector<int> vis(V,false);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(vis[i]==false){
            dfs(i,adj,vis,st);
        }
    }
    vector<int> tra[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            tra[adj[i][j]].push_back(i);
        }
        vis[i]=false;
    }
    int c=0;
    while(st.size()>0){
        int u = st.top();st.pop();
        if(vis[u]==false){
            dfs2(u,tra,vis);
            c++;
        }
    }
    return c;
}

// { Driver Code Starts.


int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout<<kosaraju(V, adj) <<endl;
    return 0;
}


//input
// 5 5
// 1 0
// 0 2
// 2 1
// 0 3
// 3 4

// he above algorithm calls DFS, finds reverse of the graph and again calls DFS. DFS takes 
// O(V+E) for a graph represented using adjacency list. Reversing a graph
//  also takes O(V+E) time. For reversing the graph, 
//  we simple traverse all adjacency lists.
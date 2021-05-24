#include<bits/stdc++.h>

using namespace std;

enum {WHITE,GREY,BLACK};
int pre[1000];
int post[1000];
int dfs_time;
void dfs(int u,vector<int> adj[],vector<int> &vis){
    pre[u]=dfs_time++;
    vis[u]=GREY;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(vis[v]==WHITE){
            cout<<"Tree Edge : "<<(char)('a'+u)<<" -> "<<(char)('a'+v)<<endl;
            dfs(v,adj,vis);
        }else if(vis[v]==GREY){
            if(pre[v]<pre[u]){
                cout<<"Back Edge : "<<(char)('a'+u)<<" -> "<<(char)('a'+v)<<endl;
            }
        }else if(vis[v]==BLACK){
            if(pre[v]<pre[u]){
                cout<<"cross Edge : "<<(char)('a'+u)<<" -> "<<(char)('a'+v)<<endl;
            }else if(pre[v]>pre[u]){
                cout<<"Forward Edge : "<<(char)('a'+u)<<" -> "<<(char)('a'+v)<<endl;
            }
        }
    }
    vis[u]=BLACK;
    post[u]=dfs_time++;
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
    vector<int> vis(V,WHITE);
    dfs(0,adj,vis);
    cout<<endl;
    for(int i=0;i<V;i++){
        cout<<(char)('a'+i)<<" : "<<pre[i]<<"/"<<post[i]<<endl;
    }
}

//input
// 6 8
// 0 1
// 1 2
// 0 3
// 3 4
// 4 2
// 4 0
// 3 5
// 0 2
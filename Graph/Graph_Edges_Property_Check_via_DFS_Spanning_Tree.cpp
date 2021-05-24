#include<bits/stdc++.h>


using namespace std;

enum {WHITE,GREY,BLACK};

int pre[1000];
int post[1000];
int dfs_time;

void dfs(int u,vector<int> adj[],vector<int> &parent,vector<int> &color){
    color[u]=GREY;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(color[v]==WHITE){
            cout<<"Tree edge : "<<u+1<<" "<<v+1<<endl;
            parent[v]=u;
            dfs(v,adj,parent,color);
        }else if(color[v]==GREY){
            if(parent[u]==v){
                cout<<"Bidirectional edge "<<u+1<<" "<<v+1<<endl;
            }else{
                cout<<"Back Edge : "<<u+1<<" "<<v+1<<endl;
            }
        }else if(color[v]==BLACK){
            cout<<"Forward/Cross Edge : "<<u+1<<" "<<v+1<<endl;
        }
    }
    color[u]=BLACK;
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
    vector<int> parent(V,-1);
    vector<int> color(10,WHITE);
    int cnt=0;
    for(int i=0;i<V;i++){
        if(color[i]==WHITE){
            cout<<"Component "<<++cnt<<endl;
            dfs(i,adj,parent,color);
        }
    }


}
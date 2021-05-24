#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> tp;
    int in[V]={0};
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            in[adj[i][j]]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(in[i]==0)
            q.push(i);
    }
    while(q.size()>0){
        int x = q.front();q.pop();
        tp.push_back(x);
        for(int i=0;i<adj[x].size();i++){
            in[adj[x][i]]--;
            if(in[adj[x][i]]==0){ 
                q.push(adj[x][i]);
            }
        }
    }
    return tp;
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
    vector<int> res = topoSort(V,adj);
    if(res.size()!=V){
        cout<<"topological sort not possible"<<endl;
    }else{
        for(auto x:res){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
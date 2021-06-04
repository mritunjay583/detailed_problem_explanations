// time complexity O(V+E)
#include<bits/stdc++.h>


using namespace std;

int dfs_time; // time counter
int low[1000]; // lowest discovery time connected to ancestor node
int disc[1000]; // discovery time
int ap[1000]; //stores articulation points
vector<int> adj[1000];
vector<pair<int,int>> bridges; //store bridges

int dfs(int u,int p){
    int children=0;
    disc[u]=low[u]=++dfs_time;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(v==p) continue; // we dont want to go back through the same path
        if(disc[v]==0){ // if v has not been discovered
            children++;
            dfs(v,u); //recursive call to dfs
            if(disc[u]<=low[v]){  // # condition 1 of articulation point
                ap[u]=1;
            }
            if(disc[u] < low [v]){ // # condition for bridges
                bridges.push_back(make_pair(u,v));
            }
            low[u] = min(low[u],low[v]); //low[v] might be an ancestor of u
        }else{ // if v was already discovered means that we found an ancestor
            low[u] = min(low[u],disc[v]); // finds the ancestor with the least discovery time
        }
    }
    return children;
}

int main(){
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int u=0;u<V;u++){
        if(disc[u]==0){
            ap[u] = dfs(u,u) > 1 ; // # condition 2 for articulation point
        }
    }
    cout<<"Articulation Points are : ";
    for(int i=0;i<V;i++){
        if(ap[i]==1){
            cout<<i<<" ";
        }
    }
}


// input 1 : 0 3
// 5 5
// 0 1
// 0 3
// 0 2
// 1 2
// 3 4

// input 2  : 1 2
// 4 3
// 0 1
// 1 2
// 2 3

//input 3 : 1 
// 7 8
// 0 1
// 0 2
// 2 1
// 1 6
// 1 3
// 1 4
// 3 5
// 4 5
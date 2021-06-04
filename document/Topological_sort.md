1. Topological sort (or topological ordering) of a Directed Acyclic Graph (DAG) is a linear orderingof the vertices in the DAG so that vertex u comes before vertex v if edge (u → v) exists in the DAG. Every DAG has one or more topological sorts.


2. psudo code
```
vi topoSort;    // global vector to store the toposort in reverse order
void dfs2(int u) {  // change function name to differentiate with original dfs
    dfs_num[u] = DFS_BLACK;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            dfs2(v.first);
    }
    topoSort.push_back(u); // that’s is, this is the only change
}
// inside main
int main(){
    topoSort.clear();
    memset(dfs_num, DFS_WHITE, sizeof dfs_num);
    for (int i = 0; i < V; i++) // this part is the same as finding CCs
        if (dfs_num[i] == DFS_WHITE)
            dfs2(i);
    reverse(topoSort.begin(), topoSort.end());  // reverse topoSort
}
```

3.  runs in O(V + E) as with DFS

4.  Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

5.  A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.

6.  Kahn's algoritm
```
enqueue vertices with zero incoming degree into a (priority) queue;
while (queue is not empty) {
    vertex u = queue.dequeue(); put vertex u into a topological sort list;
    remove this vertex u and all outgoing edges from this vertex;
    if such removal causes vertex v to have zero incoming degree, queue.enqueue(v);
}
// if all vertex is not in topological sort list then graph contains cycle
// and then topological sort will not be possible
```


1. BFS starts with the insertion of source vertex s into a queue, then processes the queue as follows: Take out the front most vertex u from the queue, enqueue all unvisited neighbors of u, and mark them as visited.

2. BFS will visit vertex s and all vertices in the connected component
that contains s layer by layer. Thus the name is breadth-ﬁrst. BFS algorithm also runs in O(V + E)
and O(V 2 ) on a graph represented using an Adjacency List and Adjacency Matrix, respectively.


#### pseudo code
```
// inside int main() -- no recursion, so we do not need to use separate function
map<int, int> dist; dist[s] = 0; // distance from source s to s is 0 (default)
queue<int> q; q.push(s);    // start from source
while (!q.empty()) {
    int u = q.front(); q.pop(); // queue: layer by layer!
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];   // for each neighbors of u
        if (!dist.count(v.first)) { // dist.find(v.first) == dist.end() also OK
            dist[v.first] = dist[u] + 1;    // v unvisited + reachable
            q.push(v.first);    // enqueue v for next step
        } 
    } 
}
```


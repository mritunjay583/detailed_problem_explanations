```
void backtracking(state) {
    if (hit end state or invalid state)     // we need terminating/pruning condition
        return;                              // to avoid cycling and to speed up search
    for each neighbor of this state
        backtracking(neighbor);             // try all permutation

}
```
1. DFS runs in O(V + E) and O(V 2 ) if the graph is stored as Adjacency List and Adjacency Matrix, respectively.
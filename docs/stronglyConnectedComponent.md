1.  transposed graph has same strongly connected component as original graph.
2.  Condensation Graph
    1.  A graph made with SCC of the original graph
    2.  Each SCC of original graph acts as a vertex in Condensation Graph & there is an edge from SCC C_i to C_j iff  there exists a node v in C_i and u in C_j and there is an edge from v to u
    3.  Condensation Graph does not contain any cycle in it.
    
4. Lemma : if C_i & C_j are SCC and there exists edge from C_i to C_j then out[ C_i ]>out[ C_j ]

5.  claim: A DAG has atleast 1 node with in-degree 0

6.  Kosaraju's algorithm
    1.  Run DFS on the graph and assign out time of each node , then sort the list by out time of nodes
        -> or you can do DFS and store BLACK node in stack
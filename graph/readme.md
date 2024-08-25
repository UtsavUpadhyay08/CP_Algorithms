# Graph Algorithms

1. [Graph Representation](#graph-representation)
2. [Minimum Spanning Tree (MST)](#minimum-spanning-tree-mst)
   - [Prim's Algorithm](#prims-algorithm)
   - [Kruskal's Algorithm](#kruskals-algorithm)
3. [Shortest Path Algorithms](#shortest-path-algorithms)
   - [Dijkstra's Algorithm](#dijkstras-algorithm)
   - [Bellman-Ford Algorithm](#bellman-ford-algorithm)
4. [Graph Traversals](#graph-traversals)
   - [Depth-First Search (DFS)](#depth-first-search-dfs)
   - [Breadth-First Search (BFS)](#breadth-first-search-bfs)
5. [Topological Sorting](#topological-sorting)
   - [DFS-based Topological Sort](#dfs-based-topological-sort)
   - [Kahn's Algorithm](#kahns-algorithm)
6. [Strongly Connected Components (SCC)](#strongly-connected-components-scc)
   - [Kosaraju's Algorithm](#kosarajus-algorithm)
   - [Tarjan's Algorithm](#tarjans-algorithm)
7. [Cycle Detection](#cycle-detection)
   - [Cycle Detection in Undirected Graphs](#cycle-detection-in-undirected-graphs)

## Graph Representation

Graphs are represented using an adjacency list in this repository. Each node has a list of pairs where each pair contains a neighboring node and the weight of the edge connecting them.

### Code Snippet

```cpp
class Graph {
public:
    ll n;
    vector<vpll> adj; // Adjacency list: vector of pairs (neighbor, weight)
    vector<bool> vis; // Visited array
    vpll edges; // Edge list: list of edges (a, b)

    Graph(ll n) {
        this->n = n;
        adj.resize(n + 1);
        vis.resize(n + 1, false);
    }

    void addedge(ll a, ll b, ll wt = 0ll) {
        adj[a].pb({b, wt});
        edges.pb({a, b});
    }
};
```

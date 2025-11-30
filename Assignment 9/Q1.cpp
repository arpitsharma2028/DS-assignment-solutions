/*
A graph G is defined as a pair (V, E) where V is a set of nodes/vertices and E is a set of edges connecting
pairs of vertices. Graphs may be directed or undirected and may have weighted or unweighted edges.
They can be represented using an adjacency matrix, adjacency list, or edge list.
Write a program to implement the following graph algorithms:
1. Breadth First Search (BFS)
2. Depth First Search (DFS)
3. Minimum Spanning Tree (Kruskal and Prim)
4. Dijkstra's Shortest Path Algorithm
*/
#include <bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    list<pair<int,int>> *adj;   // {node, weight}

    void DFSHelper(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (auto nbr : adj[u]) {
            int v = nbr.first;
            if (!visited[v]) {
                DFSHelper(v, visited);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj = new list<pair<int,int>>[V];
    }

    // -------- Add edge (default weight = 1) ----------
    void addEdge(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    // -------- BFS (Unweighted Traversal) ----------
    void BFS(int start = 0) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (auto nbr : adj[u]) {
                int v = nbr.first;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    // -------- DFS ----------
    void DFS(int start = 0) {
        vector<bool> visited(V, false);
        cout << "\nDFS Traversal: ";
        DFSHelper(start, visited);
    }

    // -------- Prim's MST ----------
    void PrimMST(int start = 0) {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);

        key[start] = 0;

        cout << "\n\nPrim's MST:\n";

        for (int i = 0; i < V - 1; i++) {
            int u = -1;

            for (int j = 0; j < V; j++) {
                if (!inMST[j] && (u == -1 || key[j] < key[u])) {
                    u = j;
                }
            }

            inMST[u] = true;

            for (auto nbr : adj[u]) {
                int v = nbr.first;
                int w = nbr.second;

                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << endl;
        }
    }

    // -------- Kruskal helper ----------
    int findSet(vector<int>& parent, int x) {
        if (parent[x] == x) return x;
        return parent[x] = findSet(parent, parent[x]);
    }

    // -------- Kruskal MST ----------
    void KruskalMST() {
        cout << "\nKruskal's MST:\n";

        vector<tuple<int,int,int>> edges; // {weight,u,v}

        for (int u = 0; u < V; u++) {
            for (auto nbr : adj[u]) {
                int v = nbr.first, w = nbr.second;
                if (u < v) edges.push_back({w, u, v});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(V);
        for (int i = 0; i < V; i++) parent[i] = i;

        for (auto e : edges) {
            int w, u, v;
            tie(w, u, v) = e;

            int setU = findSet(parent, u);
            int setV = findSet(parent, v);

            if (setU != setV) {
                cout << u << " - " << v << " (weight " << w << ")\n";
                parent[setU] = setV;
            }
        }
    }

    // -------- Dijkstra ----------
    void Dijkstra(int start = 0) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        cout << "\nDijkstra Shortest Paths from " << start << ":\n";

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int u = top.second;
            int d = top.first;

            for (auto nbr : adj[u]) {
                int v = nbr.first, w = nbr.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " -> Distance = " << dist[i] << endl;
        }
    }
};


int main() {

    Graph g(7);

    // weighted inputs (some without weight → default = 1)
    g.addEdge(0,1,4);
    g.addEdge(0,2);   // weight defaults to 1
    g.addEdge(1,3,2);
    g.addEdge(2,4,6);
    g.addEdge(3,5);   // weight defaults to 1
    g.addEdge(4,5,5);
    g.addEdge(5,6,7);

    g.BFS();
    g.DFS();
    g.PrimMST();
    g.KruskalMST();
    g.Dijkstra();

    return 0;
}


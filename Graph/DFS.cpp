#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<list<int>> adj;

public:
    Graph(int V);
    void addEdge(int v, int e);
    void dfs(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int e) {
    adj[v].push_back(e);
}

void Graph::dfs(int s) {
    vector<bool> visited(V, false);
    stack<int> stk;

    visited[s] = true;
    stk.push(s);

    while (!stk.empty()) {
        s = stk.top();
        cout << s << " ";
        stk.pop();

        for (auto it:adj[s]) {
            if (!visited[it]) {
                visited[it] = true;
                stk.push(it);
            }
        }
    }
}

int main() {
    cout << "Enter the number of vertices and edges: ";
    int v, e;
    cin >> v >> e;

    Graph g(v + 1);

    cout << "Enter edges (u v): ";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "Enter starting vertex: ";
    int start;
    cin >> start;

    cout << "DFS starting from vertex " << start << ": ";
    g.dfs(start);

    return 0;
}

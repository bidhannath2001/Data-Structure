//Implementation of Prim's algorithm
#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    int mst(int V,vector<vector<int>> adj[]){
        //priority queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        pq.push({0,0});
        int sum = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            
            if(vis[node]==1) continue;
            
            vis[node]=1;
            sum+=wt;

            for(auto neighbor : adj[node]){
                int adjNode = neighbor[0];
                int edW = neighbor[1];

                if(!vis[adjNode]){
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};

int main() {
    // Example graph representation using an adjacency list
    int V = 4;
    vector<vector<int>> adj[V];

    // Adding edges to the graph
    adj[0].push_back({1, 2});  // Edge from node 0 to node 1 with weight 2
    adj[1].push_back({0, 2});  // Edge from node 1 to node 0 with weight 2
    adj[1].push_back({2, 1});  // Edge from node 1 to node 2 with weight 1
    adj[2].push_back({1, 1});  // Edge from node 2 to node 1 with weight 1
    adj[2].push_back({3, 3});  // Edge from node 2 to node 3 with weight 3
    adj[3].push_back({2, 3});  // Edge from node 3 to node 2 with weight 3

    solution sol;
    int minSpanningTreeWeight = sol.mst(V, adj);

    cout << "Weight of Minimum Spanning Tree: " << minSpanningTreeWeight << endl;

    return 0;
}

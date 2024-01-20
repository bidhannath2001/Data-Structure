#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V,E;
    vector<list<int>>adj;
    public:
    Graph(int V);
    void addEdge(int v,int e);
    void bfs(int s);
};
Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}
void Graph::addEdge(int v,int e){
    adj[v].push_back(e);
}
void Graph::bfs(int s){
    vector<bool>visited;
    visited.resize(V,false);
    queue<int>q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        s = q.front();
        cout<<s<<" ";
        q.pop();
        for(auto it:adj[s]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
            }
        }
    }
}
int main (){
    cout << "Enter the number of vertices and edges: ";
    int v,e;
    cin>>v>>e;
    Graph g(v+1);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    cout<<"Enter starting vartex: ";
    int start;
    cin>>start;
    g.bfs(start);
    return 0;
}
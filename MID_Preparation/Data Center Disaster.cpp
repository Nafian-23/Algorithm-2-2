#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // Adjacency list: {neighbor, weight}
    vector<pair<int, long long>> adjList[n + 1];
    
    for(int i = 0; i < m; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        adjList[u].push_back({v, c});
        adjList[v].push_back({u, c});
    }
    
    // Prim's Algorithm
    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> pq;
    
    vector<bool> visited(n + 1, false);
    vector<long long> minEdge(n + 1, LLONG_MAX);
    
    long long mstCost = 0;
    int nodesInMST = 0;
    
    // Start from node 1
    minEdge[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()) {
        int node = pq.top().second;
        long long edgeWeight = pq.top().first;
        pq.pop();
        
        // If already in MST, skip
        if(visited[node]) continue;
        
        // Add to MST
        visited[node] = true;
        mstCost += edgeWeight;
        nodesInMST++;
        
        // Explore neighbors
        for(int i = 0; i < adjList[node].size(); i++) {
            int neighbor = adjList[node][i].first;
            long long weight = adjList[node][i].second;
            
            if(!visited[neighbor] && weight < minEdge[neighbor]) {
                minEdge[neighbor] = weight;
                pq.push({weight, neighbor});
            }
        }
    }
    
    // Check if all nodes are connected
    if(nodesInMST == n) {
        cout << mstCost << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}
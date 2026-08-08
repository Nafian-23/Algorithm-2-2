#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adjList[n + 1];
    
    for(int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        adjList[u].push_back({v, x});
        adjList[v].push_back({u, x});
    }
    
    // Dijkstra with parent tracking
    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> p;
    p.push({0, 1});
    
    vector<bool> explore(n + 1, 0);
    vector<long long> dis(n + 1, LLONG_MAX);
    vector<int> parent(n + 1, -1);        // Track previous node
    vector<long long> edgeWeight(n + 1, 0); // Track weight of edge used
    
    dis[1] = 0;
    
    while(!p.empty()) {
        int node = p.top().second;
        p.pop();
        
        if(explore[node] == 1) continue;
        explore[node] = 1;
        
        for(int i = 0; i < adjList[node].size(); i++) {
            int neighbour = adjList[node][i][0];
            long long weight = adjList[node][i][1];
            
            if(!explore[neighbour] && dis[node] + weight < dis[neighbour]) {
                dis[neighbour] = dis[node] + weight;
                parent[neighbour] = node;           // Store who we came from
                edgeWeight[neighbour] = weight;     // Store the edge weight
                p.push({dis[neighbour], neighbour});
            }
        }
    }
    
    // Reconstruct path from N to 1
    long long maxEdge = 0;
    int current = n;
    
    while(current != 1) {
        maxEdge = max(maxEdge, edgeWeight[current]);
        current = parent[current];
    }
    
    cout << maxEdge << endl;
    
    return 0;
}
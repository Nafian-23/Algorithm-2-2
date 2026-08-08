#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, long long>> adjList[n + 1];
    
    for(int i = 0; i < m; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        adjList[u].push_back({v, c});
        adjList[v].push_back({u, c});
    }
    
    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> pq;
    
    vector<bool> visited(n + 1, false);
    vector<long long> minEdge(n + 1, LLONG_MAX);
    
    long long mstCost = 0;
    int nodesVisited = 0;
    
    minEdge[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()) {
        int node = pq.top().second;
        long long weight = pq.top().first;
        pq.pop();
        
        if(visited[node]) continue;
        
        visited[node] = true;
        mstCost += weight;
        nodesVisited++;
        
        for(int i = 0; i < adjList[node].size(); i++) {
            int neighbour = adjList[node][i].first;
            long long edgeWeight = adjList[node][i].second;
            
            if(!visited[neighbour] && edgeWeight < minEdge[neighbour]) {
                minEdge[neighbour] = edgeWeight;
                pq.push({edgeWeight, neighbour});
            }
        }
    }
    
    if(nodesVisited == n) {
        cout << mstCost << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}
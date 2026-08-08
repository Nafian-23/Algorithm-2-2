#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // Adjacency list: each edge has {neighbor, time, toll}
    // Using vector of vectors of vectors (like your template)
    // adjList[u] contains {v, time, toll}
    vector<vector<int>> adjList[n+1];
    
    for(int i = 0; i < m; i++) {
        int u, v, t, c;
        cin >> u >> v >> t >> c;
        adjList[u].push_back({v, t, c});
        adjList[v].push_back({u, t, c});
    }
    
    // Arrays to store minimum time and toll
    vector<long long> minTime(n+1, LLONG_MAX);
    vector<long long> minToll(n+1, LLONG_MAX);
    vector<bool> visited(n+1, false);
    
    // Priority queue: {time, node}
    // We use time as primary key (like regular Dijkstra)
    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> pq;
    
    // Start from city 1
    minTime[1] = 0;
    minToll[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()) {
        int node = pq.top().second;
        long long currentTime = pq.top().first;
        pq.pop();
        
        if(visited[node]) continue;
        visited[node] = true;
        
        // Explore neighbors
        for(int i = 0; i < adjList[node].size(); i++) {
            int neighbor = adjList[node][i][0];
            long long edgeTime = adjList[node][i][1];
            long long edgeToll = adjList[node][i][2];
            
            long long newTime = currentTime + edgeTime;
            long long newToll = minToll[node] + edgeToll;
            
            if(!visited[neighbor]) {
                // If we found a shorter time path
                if(newTime < minTime[neighbor]) {
                    minTime[neighbor] = newTime;
                    minToll[neighbor] = newToll;
                    pq.push({newTime, neighbor});
                }
                // If we found same time but cheaper toll
                else if(newTime == minTime[neighbor] && newToll < minToll[neighbor]) {
                    minToll[neighbor] = newToll;
                    pq.push({newTime, neighbor});
                }
            }
        }
    }
    
    cout << minToll[n] << endl;
    
    return 0;
}
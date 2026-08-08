#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

vector<long long> dijkstra(vector<vector<int>> adjList[], int src, int vertex) {
    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> p;
    p.push({0, src});
    
    vector<bool> explore(vertex + 1, 0);
    vector<long long> dis(vertex + 1, LLONG_MAX);
    dis[src] = 0;
    
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
                p.push({dis[neighbour], neighbour});
            }
        }
    }
    return dis;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    // Adjacency list for roads
    vector<vector<int>> adjList[n + 1];
    
    // Read m roads
    for(int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        adjList[u].push_back({v, x});
        adjList[v].push_back({u, x});
    }
    
    // Store train routes
    vector<pair<int, int>> trains(k);
    for(int i = 0; i < k; i++) {
        int s, y;
        cin >> s >> y;
        trains[i].first = s;
        trains[i].second = y;
    }
    
    // Run Dijkstra from capital (city 1) using ONLY roads
    vector<long long> roadDist = dijkstra(adjList, 1, n);
    
    // For each city, keep track of the minimum train length
    vector<long long> minTrain(n + 1, LLONG_MAX);
    vector<int> trainCount(n + 1, 0);
    
    for(int i = 0; i < k; i++) {
        int city = trains[i].first;
        long long len = trains[i].second;
        minTrain[city] = min(minTrain[city], len);
        trainCount[city]++;
    }
    
    // Count how many trains we MUST keep
    int mustKeep = 0;
    
    // Check each city that has trains
    for(int city = 2; city <= n; city++) {
        if(trainCount[city] > 0) {
            // If the best train is strictly better than road, we must keep 1 train
            if(minTrain[city] < roadDist[city]) {
                mustKeep++;  // Keep the best train for this city
            }
            // If train is equal or worse, we keep 0 trains for this city
        }
    }
    
    // Answer = total trains - trains we must keep
    int canClose = k - mustKeep;
    
    cout << canClose << endl;
    
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>> adjList[], int src, int vertex) {
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>> p;
    p.push({0, src});
    
    vector<bool> explore(vertex, 0);
    vector<int> dis(vertex, INT_MAX);
    dis[src] = 0;
    
    while(!p.empty()) {
        int node = p.top().second;
        p.pop();
        
        if(explore[node] == 1) continue;
        explore[node] = 1;
        
        for(int i = 0; i < adjList[node].size(); i++) {
            int neighbour = adjList[node][i][0];
            int weight = adjList[node][i][1];
            
            if(!explore[neighbour] && dis[node] + weight < dis[neighbour]) {
                dis[neighbour] = dis[node] + weight;
                p.push({dis[neighbour], neighbour});
            }
        }
    }
    return dis;
}

int main() {
    int N;
    cin >> N;
    
    for(int caseNum = 1; caseNum <= N; caseNum++) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        
        // Adjacency list for this test case
        vector<vector<int>> adjList[n];
        
        // Read m cables (edges)
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
        
        // Run Dijkstra from source S
        vector<int> dist = dijkstra(adjList, S, n);
        
        // Output result
        cout << "Case #" << caseNum << ": ";
        if(dist[T] == INT_MAX) {
            cout << "unreachable" << endl;
        } else {
            cout << dist[T] << endl;
        }
    }
    
    return 0;
}
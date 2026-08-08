#include<iostream>
#include<vector>
#include<queue>
#include<climits>
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
    int n, m, s, d, c;
    cin >> n >> m >> s >> d >> c;
    
    vector<vector<int>> adjList[n + 1];
    
    for(int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        adjList[u].push_back({v, x});
        adjList[v].push_back({u, x});
    }
    
    // Run Dijkstra from S
    vector<long long> distFromS = dijkstra(adjList, s, n);
    long long disS_C = distFromS[c];
    
    // Run Dijkstra from C
    vector<long long> distFromC = dijkstra(adjList, c, n);
    long long disC_D = distFromC[d];
    
    // Total = S → C + C → D
    long long total = disS_C + disC_D;
    
    cout << total << endl;
    
    return 0;
}
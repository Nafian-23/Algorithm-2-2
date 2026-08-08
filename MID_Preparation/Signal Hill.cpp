#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int main() {
    int B, Q;
    cin >> B >> Q;
    
    // Store beacon information: {x, y, range}
    vector<int> x(B + 1), y(B + 1), r(B + 1);
    
    for(int i = 1; i <= B; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    
    // Build directed graph
    vector<vector<int>> adjList[B + 1];
    
    // Check which beacons can reach which
    for(int i = 1; i <= B; i++) {
        for(int j = 1; j <= B; j++) {
            if(i != j) {
                // Calculate squared distance to avoid floating point
                long long dx = x[i] - x[j];
                long long dy = y[i] - y[j];
                long long distSq = dx * dx + dy * dy;
                long long rangeSq = (long long)r[i] * r[i];
                
                // If beacon j is within beacon i's range
                if(distSq <= rangeSq) {
                    adjList[i].push_back({j});
                }
            }
        }
    }
    
    // Process queries
    for(int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b;
        
        // BFS/DFS from beacon a to check if b is reachable
        vector<bool> visited(B + 1, false);
        queue<int> que;
        
        que.push(a);
        visited[a] = true;
        
        bool canReach = false;
        
        while(!que.empty()) {
            int current = que.front();
            que.pop();
            
            if(current == b) {
                canReach = true;
                break;
            }
            
            for(int i = 0; i < adjList[current].size(); i++) {
                int neighbour = adjList[current][i][0];
                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    que.push(neighbour);
                }
            }
        }
        
        if(canReach) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
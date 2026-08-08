#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Disjoint Set Union (DSU) - Union Find
vector<int> parent;
vector<int> rank;  // Changed from size to rank

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);  // Path compression
}

void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    
    if(rootA != rootB) {
        // Union by rank
        if(rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        }
        else if(rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        }
        else {
            // If ranks are equal, make one root and increment its rank
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // Initialize DSU
    parent.resize(n + 1);
    rank.resize(n + 1, 0);  // Initially all ranks are 0
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    // Store edges
    struct Edge {
        int u, v;
        long long cost;
        bool critical;
    };
    
    vector<Edge> criticalEdges;
    vector<Edge> optionalEdges;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        long long c;
        int t;
        cin >> a >> b >> c >> t;
        
        if(t == 1) {
            criticalEdges.push_back({a, b, c, true});
        } else {
            optionalEdges.push_back({a, b, c, false});
        }
    }
    
    long long totalCost = 0;
    int edgesUsed = 0;
    
    // Step 1: Process all critical edges FIRST
    for(int i = 0; i < criticalEdges.size(); i++) {
        int u = criticalEdges[i].u;
        int v = criticalEdges[i].v;
        long long cost = criticalEdges[i].cost;
        
        if(find(u) == find(v)) {
            // Critical edges form a cycle - IMPOSSIBLE
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        
        unite(u, v);
        totalCost += cost;
        edgesUsed++;
    }
    
    // Step 2: Sort optional edges by cost (for Kruskal's)
    sort(optionalEdges.begin(), optionalEdges.end(), 
         [](Edge a, Edge b) { return a.cost < b.cost; });
    
    // Step 3: Add optional edges to complete MST
    for(int i = 0; i < optionalEdges.size(); i++) {
        int u = optionalEdges[i].u;
        int v = optionalEdges[i].v;
        long long cost = optionalEdges[i].cost;
        
        if(find(u) != find(v)) {
            unite(u, v);
            totalCost += cost;
            edgesUsed++;
        }
        
        // If we already have n-1 edges, we're done
        if(edgesUsed == n - 1) break;
    }
    
    // Check if we connected all nodes
    if(edgesUsed == n - 1) {
        cout << totalCost << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}
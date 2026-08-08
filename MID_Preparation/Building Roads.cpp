#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;
vector<int> rank;

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    
    if(rootA != rootB) {
        if(rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        }
        else if(rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        }
        else {
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
    rank.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    // Process existing roads
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }
    
    // Find all component representatives (roots)
    vector<int> components;
    for(int i = 1; i <= n; i++) {
        if(find(i) == i) {  // This is a root
            components.push_back(i);
        }
    }
    
    // Number of new roads needed
    int k = components.size() - 1;
    cout << k << endl;
    
    // Connect components: link each component to the next one
    for(int i = 0; i < k; i++) {
        cout << components[i] << " " << components[i + 1] << endl;
    }
    
    return 0;
}
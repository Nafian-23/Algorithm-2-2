#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge {
    int u, v, w, id;
};

vector<int> parent, sz;

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) {
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
    }
    
    // Sort by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });
    
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    for(int i = 1; i <= n; i++) parent[i] = i;
    
    vector<string> answer(m);
    
    int i = 0;
    while(i < m) {
        int j = i;
        // Group edges by same weight
        while(j < m && edges[j].w == edges[i].w) {
            j++;
        }
        
        // First: Mark edges
        for(int k = i; k < j; k++) {
            int u = edges[k].u, v = edges[k].v;
            if(find(u) == find(v)) {
                answer[edges[k].id] = "none";
            } else {
                answer[edges[k].id] = "at least one";
            }
        }
        
        // Second: Check which "at least one" edges are "any"
        for(int k = i; k < j; k++) {
            if(answer[edges[k].id] == "none") continue;
            
            int u = edges[k].u, v = edges[k].v;
            if(find(u) != find(v)) {
                // This edge connects two different components
                // If it's the ONLY edge doing so in this weight group, it's "any"
                answer[edges[k].id] = "any";
            }
        }
        
        // Third: Actually unite all edges that aren't "none"
        for(int k = i; k < j; k++) {
            if(answer[edges[k].id] != "none") {
                int u = edges[k].u, v = edges[k].v;
                if(find(u) != find(v)) {
                    unite(u, v);
                }
            }
        }
        
        i = j;
    }
    
    for(int i = 0; i < m; i++) {
        cout << answer[i] << endl;
    }
    
    return 0;
}
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> qual(n + 1);
    int maxQual = -1;
    int root = -1;
    
    // Read qualifications and find the root
    for(int i = 1; i <= n; i++) {
        cin >> qual[i];
        if(qual[i] > maxQual) {
            maxQual = qual[i];
            root = i;
        }
    }
    
    int m;
    cin >> m;
    
    // For each employee, find the minimum cost to supervise them
    vector<long long> minCost(n + 1, LLONG_MAX);
    
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        // a supervises b, so b's incoming edge cost is c
        // Keep the minimum cost for each subordinate
        if(c < minCost[b]) {
            minCost[b] = c;
        }
    }
    
    long long totalCost = 0;
    bool possible = true;
    
    // Each employee except root needs exactly one supervisor
    for(int i = 1; i <= n; i++) {
        if(i == root) continue;  // Root doesn't need a supervisor
        
        if(minCost[i] == LLONG_MAX) {
            // No one can supervise this employee
            possible = false;
            break;
        }
        
        totalCost += minCost[i];
    }
    
    if(possible) {
        cout << totalCost << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
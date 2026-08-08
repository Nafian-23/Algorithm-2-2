#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Distance matrix
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1));
    
    // Read the cost matrix
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }
    
    // Read opening order
    vector<int> openOrder(n);
    for(int i = 0; i < n; i++) {
        cin >> openOrder[i];
    }
    
    // Track which warehouses are open
    vector<bool> isOpen(n + 1, false);
    
    // Store answers
    vector<long long> answers;
    
    // Process each warehouse as it opens
    for(int idx = 0; idx < n; idx++) {
        int k = openOrder[idx];  // New warehouse that opens
        isOpen[k] = true;
        
        // Use new warehouse k as intermediate for all pairs
        // Update shortest paths between ALL warehouses (including currently closed ones)
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        
        // Calculate sum of all pairs among OPEN warehouses
        long long total = 0;
        for(int i = 1; i <= n; i++) {
            if(isOpen[i]) {
                for(int j = 1; j <= n; j++) {
                    if(isOpen[j] && i != j) {
                        total += dist[i][j];
                    }
                }
            }
        }
        
        answers.push_back(total);
    }
    
    // Print answers
    for(int i = 0; i < answers.size(); i++) {
        cout << answers[i];
        if(i < answers.size() - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
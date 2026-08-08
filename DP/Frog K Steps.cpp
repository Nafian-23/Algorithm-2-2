#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> h(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    
    vector<long long> dp(n + 1, LLONG_MAX);
    
    // Base case
    dp[1] = 0;
    
    // Fill DP table
    for(int i = 2; i <= n; i++) {
        // Check all possible previous stones
        for(int j = max(1, i - k); j < i; j++) {
            long long cost = dp[j] + abs(h[i] - h[j]);
            dp[i] = min(dp[i], cost);
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
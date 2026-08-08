#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> cost(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    
    vector<long long> dp(n + 1, 0);
    
    // Base cases
    dp[1] = cost[1];
    
    if(n >= 2) {
        dp[2] = cost[1] + cost[2];
    }
    
    // Fill DP table
    for(int i = 3; i <= n; i++) {
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
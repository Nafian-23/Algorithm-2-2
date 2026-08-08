#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    long long t;
    cin >> n >> t;
    
    vector<long long> c(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    
    vector<long long> dp(n + 1, 0);
    
    // Base cases
    dp[1] = c[1];
    
    if(n >= 2) {
        dp[2] = dp[1] + c[2];  // Only way: 1→2
    }
    
    // Fill DP table
    for(int i = 3; i <= n; i++) {
        long long fromOneStep = dp[i-1] + c[i];           // 1-step jump, no toll
        long long fromTwoStep = dp[i-2] + c[i] + t;       // 2-step jump, pay toll
        
        dp[i] = min(fromOneStep, fromTwoStep);
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<bool> blocked(n + 1, false);
    
    for(int i = 0; i < m; i++) {
        int step;
        cin >> step;
        blocked[step] = true;
    }
    
    vector<long long> dp(n + 1, 0);
    
    // Base case
    dp[0] = 1;
    
    // Fill DP table
    for(int i = 1; i <= n; i++) {
        if(blocked[i]) {
            dp[i] = 0;  // Can't land on blocked step
            continue;
        }
        
        // From 1 step back
        if(i - 1 >= 0 && !blocked[i-1]) {
            dp[i] += dp[i-1];
        }
        
        // From 2 steps back
        if(i - 2 >= 0 && !blocked[i-2]) {
            dp[i] += dp[i-2];
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}

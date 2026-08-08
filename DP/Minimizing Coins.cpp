#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    vector<long long> dp(x + 1, INT_MAX);
    
    // Base case
    dp[0] = 0;
    
    // Fill DP table
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    
    if(dp[x] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }
    
    return 0;
}
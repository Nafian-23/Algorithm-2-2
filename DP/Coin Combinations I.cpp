#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    vector<long long> dp(x + 1, 0);
    
    // Base case
    dp[0] = 1;
    
    // Fill DP table - sum first (ordered counting)
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if(coins[j] <= i) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }
    
    cout << dp[x] << endl;
    
    return 0;
}
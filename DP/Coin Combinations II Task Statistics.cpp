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
    
    // Fill DP table - coins first (unordered counting)
    for(int j = 0; j < n; j++) {
        int coin = coins[j];
        for(int i = coin; i <= x; i++) {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }
    
    cout << dp[x] << endl;
    
    return 0;
}
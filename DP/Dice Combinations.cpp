#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1000000007;  // 10^9 + 7

int main() {
    int n;
    cin >> n;
    
    vector<long long> dp(n + 1, 0);
    
    // Base case
    dp[0] = 1;
    
    // Fill DP table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6; j++) {
            if(i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<long long> dp(n + 1, 0);
    
    // Base cases
    dp[0] = 0;
    dp[1] = a[1];
    
    // Fill DP table
    for(int i = 2; i <= n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + a[i]);
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
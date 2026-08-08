#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> dp(n + 1, INT_MAX);
    
    // Base case
    dp[0] = 0;
    
    // Fill DP table
    for(int i = 1; i <= n; i++) {
        // Try all digits of i
        int num = i;
        while(num > 0) {
            int digit = num % 10;
            num /= 10;
            
            if(digit > 0 && i - digit >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - digit]);
            }
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
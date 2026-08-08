#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<long long> dp(n, 0);
    
    // Initialize: each element alone
    for(int i = 0; i < n; i++) {
        dp[i] = arr[i];
    }
    
    // Fill DP table
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    
    // Find maximum
    long long answer = 0;
    for(int i = 0; i < n; i++) {
        answer = max(answer, dp[i]);
    }
    
    cout << answer << endl;
    
    return 0;
}
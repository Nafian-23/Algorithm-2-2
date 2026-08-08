#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> coins(n);
    int totalSum = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
        totalSum += coins[i];
    }
    
    vector<bool> dp(totalSum + 1, false);
    
    // Base case
    dp[0] = true;
    
    // Process each coin
    for(int i = 0; i < n; i++) {
        // Reverse loop: each coin used at most once
        for(int j = totalSum; j >= coins[i]; j--) {
            if(dp[j - coins[i]]) {
                dp[j] = true;
            }
        }
    }
    
    // Count and collect all possible sums
    vector<int> possible;
    for(int sum = 1; sum <= totalSum; sum++) {
        if(dp[sum]) {
            possible.push_back(sum);
        }
    }
    
    // Output
    cout << possible.size() << endl;
    for(int i = 0; i < possible.size(); i++) {
        cout << possible[i];
        if(i < possible.size() - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
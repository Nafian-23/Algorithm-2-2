#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> price(n), pages(n);
    
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    
    vector<int> dp(x + 1, 0);
    
    // Process each book
    for(int i = 0; i < n; i++) {
        // Reverse loop: each book used at most once
        for(int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }
    
    cout << dp[x] << endl;
    
    return 0;
}
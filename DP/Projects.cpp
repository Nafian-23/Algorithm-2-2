#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Project {
    int start, end;
    long long reward;
};

// Compare by end time
bool compare(Project a, Project b) {
    return a.end < b.end;
}

// Binary search: find last project ending before 'start'
int findLast(vector<Project>& projects, int index) {
    int startTime = projects[index].start;
    int low = 0, high = index - 1;
    int result = -1;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        if(projects[mid].end < startTime) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return result;  // -1 if no valid project
}

int main() {
    int n;
    cin >> n;
    
    vector<Project> projects(n);
    for(int i = 0; i < n; i++) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }
    
    // Sort by end time
    sort(projects.begin(), projects.end(), compare);
    
    vector<long long> dp(n, 0);
    
    // Base case: first project
    dp[0] = projects[0].reward;
    
    for(int i = 1; i < n; i++) {
        // Option 1: skip project i
        long long skip = dp[i-1];
        
        // Option 2: take project i
        int last = findLast(projects, i);
        long long take = projects[i].reward;
        if(last != -1) {
            take += dp[last];
        }
        
        dp[i] = max(skip, take);
    }
    
    cout << dp[n-1] << endl;
    
    return 0;
}
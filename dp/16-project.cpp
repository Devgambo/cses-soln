#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vc = vector<char>;
using vll = vector<ll>;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
#define pb push_back
#define ff first
#define ss second

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Binary search to find the latest project that ends before 'start' time
int findLastCompatible(vector<array<ll, 3>>& projects, int i, ll start) {
    int left = 0, right = i - 1, lastCompatible = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(projects[mid][1] < start){
            lastCompatible = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return lastCompatible;
}

int main() {
    fast_io();
    int n;
    cin >> n;
    
    // Store projects as {start, end, profit}
    vector<array<ll, 3>> projects(n);
    for(int i = 0; i < n; i++){
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }
    
    // Sort by ending time
    sort(projects.begin(), projects.end(), [](auto& a, auto& b){
        return a[1] < b[1];
    });
    
    // dp[i] = max profit considering projects 0 to i
    vll dp(n);
    dp[0] = projects[0][2]; // Take the first project
    
    for(int i = 1; i < n; i++){
        ll start = projects[i][0];
        ll profit = projects[i][2];
        
        // Option 1: Don't take project i
        dp[i] = dp[i-1];
        
        // Option 2: Take project i
        // Find the latest project that ends before this one starts
        int lastCompatible = findLastCompatible(projects, i, start);
        
        ll takeProfit = profit;
        if(lastCompatible != -1){
            takeProfit += dp[lastCompatible];
        }
        
        dp[i] = max(dp[i], takeProfit);
    }
    
    cout << dp[n-1] << endl;
    
    // Time: O(n log n) for sorting + O(n log n) for DP with binary search
    // Space: O(n)
    
    return 0;
}




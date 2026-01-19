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

int main() {
    fast_io();
    int n;
    cin >> n;
    vi a(n);
    int maxSum = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        maxSum += a[i];
    }
    
    // dp[s] = true if sum 's' is achievable
    vector<bool> dp(maxSum + 1, false);
    
    // Base case: we can always make sum 0 (by taking no coins)
    dp[0] = true;
    
    // For each coin
    for(int i = 0; i < n; i++){
        // Iterate backwards to avoid using the same coin multiple times
        for(int s = maxSum; s >= a[i]; s--){
            if(dp[s - a[i]]){
                dp[s] = true;
            }
        }
    }


    
    vi result;
    for(int s = 1; s <= maxSum; s++){
        if(dp[s]){
            result.pb(s);
        }
    }
    
    cout << result.size() << endl;
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;
    
    // Time Complexity: O(n * maxSum) where maxSum = sum of all coins
    // Space Complexity: O(maxSum)
    
    return 0;
}
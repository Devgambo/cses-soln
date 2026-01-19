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

// Transition logic:
// Pick left: a[i] + (remaining sum after opponent plays)
// Pick right: a[j] + (remaining sum after opponent plays)
// The "remaining sum" = totalSum - picked_value - dp[next_range]
// Because dp[next_range] tells us how much the opponent will take


int main() {
    fast_io();
    int n;
    cin >> n;
    vll a(n);
    vll prefix(n + 1, 0);
    for(int i=0; i<n; i++){
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }

    auto rangeSum = [&](int i, int j) -> ll {
        return prefix[j + 1] - prefix[i];
    };

    // dp[i][j] = max score current player can get from range [i, j]
    vector<vll> dp(n, vll(n, 0));

    // Base case: single element
    for(int i = 0; i < n; i++){
        dp[i][i] = a[i];
    }

    // Fill DP table for increasing lengths
    for(int len = 2; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;    //end index of the range
            
            ll totalSum = rangeSum(i, j);
            
            // Option 1: Pick left element a[i] 
            ll pickLeft = totalSum - dp[i+1][j];
            
            // Option 2: Pick right element a[j]
            ll pickRight = totalSum - dp[i][j-1];
            
            dp[i][j] = max(pickLeft, pickRight);
        }
    }

    cout << dp[0][n-1] << endl;
    // Time: O(n^2), Space: O(n^2)
    return 0;
}




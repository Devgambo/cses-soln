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
    vector<vc> gr(n, vc(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> gr[i][j];
        }
    }

    vector<vll> dp(n, vll(n, 0));

    // Check if start or end is blocked
    if(gr[0][0] == '*' || gr[n-1][n-1] == '*') {
        cout << 0;
        return 0;
    }
    
    dp[0][0] = 1;
    
    // Fill first row
    for(int j=1; j<n; j++){
        if(gr[0][j] != '*'){
            dp[0][j] = dp[0][j-1];
        }
    }
    
    // Fill first column
    for(int i=1; i<n; i++){
        if(gr[i][0] != '*'){
            dp[i][0] = dp[i-1][0];
        }
    }
    
    // Fill rest of the grid
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(gr[i][j] != '*'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }

    cout << dp[n-1][n-1];


    return 0;
}
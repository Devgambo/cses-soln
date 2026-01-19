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
    int n , m;
    cin >> n >> m;

    vector<vi> dp(n+1, vi(m+1, INF));

    for(int i=1; i<=n; i++){
        for(int j=1;j<=m; j++){
            if(i==j){
                dp[i][j] = 0;
                continue;
            }
            
            // Try all horizontal cuts
            for(int k=1; k<i; k++){
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
            }
            
            // Try all vertical cuts
            for(int k=1; k<j; k++){
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
            }
        }
    }
    cout << dp[n][m];
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
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
    ll x;
    cin >> n >> x;
    vll coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    // dp[i][k] : no. of ways to get a sum k where all the coins from ci - cn are pickable.
    // pickable - we can pick them, cond : c(i) < c(i+1) 
    // we're doing this to restrict the diff. permutations
    //bc : dp[i][0] = 1, we have to make 0 , not gonna pick any :: one way
    //final subm : dp[0][x];

    //bc
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }

    for(int i=n-1; i>=0; i--){
        for(int k = 1; k <= x; k++){
            int notpick = dp[i+1][k];
            int pick = 0;
            if(coins[i] <= k){
                pick = dp[i][k-coins[i]];
            }

            dp[i][k] = (pick + notpick)%MOD;
        }
    } 
    
    cout << dp[0][x];
    return 0;
}
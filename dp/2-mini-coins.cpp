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

    vector<ll> dp(x + 1, INF);
    //dp[i]: min coins required to form sum i
    
    //base case: 0 coins needed for sum 0
    dp[0] = 0;

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i >= coins[j] && dp[i - coins[j]] != INF){
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    
    cout << (dp[x] == INF ? -1 : dp[x]);
    return 0;
}
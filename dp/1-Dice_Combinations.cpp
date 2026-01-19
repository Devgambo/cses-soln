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
    ll n;
    cin >> n;

    vector<ll> dp(n+1,0);
    dp[0] = 1;

    //dp[i]: no of ways to make i

    for(ll i=1; i<=n; i++){
        for(int d=1; d<7; d++){
            if(i >= d) {
                dp[i] = (dp[i] + dp[i-d]) % MOD;
            }
        }
    }

    cout << dp[n];

    return 0;
}
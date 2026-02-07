#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const long long INF = 1e15;
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


ll ipow(ll base, int exp) {
    ll result = 1;
    for (int i = 0; i < exp; ++i) result *= base;
    return result;
}

int main() {
    fast_io();

    map<ll, ll> mp;
    for (int i = 0; i <= 20; i++) {
        ll k = ipow(3, i);
        ll v = ipow(3, i + 1);
        if (i > 0) v += i * ipow(3, i - 1);
        mp[k] = v;
    }

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, INF));

        for (int j = 0; j <= k; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (auto &it : mp) {
                    ll k = it.first;
                    ll v = it.second;
                    if (i - k >= 0) {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + v);
                    }
                }
            }
        }

        ll result = dp[n][k];
        cout << (result == INF ? -1 : result) << "\n";
    }

    return 0;
}

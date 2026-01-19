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
    int n, x;
    cin >> n >> x;
    vi h(n), s(n);
    for(int i=0; i<n; i++)  cin >> h[i];
    for(int i=0; i<n; i++)  cin >> s[i];

    vector<int> dp(x+1,0);

    for(int i=0; i<n; i++){
        //cuz we need dp[i-smtg] therefore we cannot go 0-x as we may update the thing we need in future.
        for(int pr = x; pr >= h[i]; pr--){
            int npk = dp[pr] + 0;
            int pk = dp[pr-h[i]] + s[i];
            dp[pr] = max(pk,npk);
        }
    }

    cout << dp[x];

    return 0;
}
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
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        
        if (k > n) {
            cout << -1 << endl;
            continue;
        }
        if (k == n) {
            cout << 0 << endl;
            continue;
        }
        
        ll lo = k, hi = k;
        ll ans = 0;
        
        while (hi < n) {
            ans++;
            lo = 2 * lo - 1;
            hi = 2 * hi + 1;
        }
        
        if (lo <= n && n <= hi) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
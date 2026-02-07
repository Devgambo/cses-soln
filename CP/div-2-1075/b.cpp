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
    while(t--) {
        int n;
        ll x;
        cin >> n >> x;
        
        ll noroll = 0;
        ll maxmove = 0;
        
        for(int i = 0; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            noroll += (b - 1) * a;
            maxmove = max(maxmove, b * a - c);
        }
        
        if(x <= noroll) {
            cout << 0 << endl;
        } else if(maxmove <= 0) {
            cout << -1 << endl;
        } else {
            ll remaining = x - noroll;
            ll ans = (ll)(remaining + maxmove - 1) / maxmove;
            cout << ans << endl;
        }
    }
    return 0;
}
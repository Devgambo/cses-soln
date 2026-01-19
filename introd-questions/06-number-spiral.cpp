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
    ll t;
    cin >> t;
    while(t>0){
        t--;
        ll x, y;
        cin >> x >> y;
        ll ans;
        if (x >= y) {
            if (x % 2 == 0) {
                ans = x * x - y + 1;
            } else {
                ans = (x - 1) * (x - 1) + y;
            }
        } else {
            if (y % 2 == 1) {
                ans = y * y - x + 1;
            } else {
                ans = (y - 1) * (y - 1) + x;
            }
        }
        cout << ans << endl;
    }
    return  0;
}
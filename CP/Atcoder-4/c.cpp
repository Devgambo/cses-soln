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
#define pb push_back
#define ff first
#define ss second

const int MOD = 998244353;
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
    int n;
    cin >> n;

    vector<ll> both(n);
    ll S = 0;

    for (int i = 0; i < n; i++) {
        ll W, P;
        cin >> W >> P;
        both[i] = W + P;
        S += P;
    }
    ll used = 0;
    sort(both.begin(), both.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (used + both[i] <= S) {
            used += both[i];
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;
    }


    return 0;
}
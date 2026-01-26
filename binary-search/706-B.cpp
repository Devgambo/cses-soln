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
    int n, q;
    cin >> n;
    vi x(n);
    for(int i=0; i<n; i++)  cin >> x[i];
    cin >> q;
    vll m(q);
    for(int i=0; i<q; i++)  cin >> m[i];

    sort(x.begin(), x.end());

    for(int i=0; i<q; i++){
        auto ub = upper_bound(x.begin(), x.end(), m[i]);
        cout << ub - x.begin() << endl;
    }
    return 0;
}
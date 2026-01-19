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

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll solve(int i, ll cur, ll sm, const vll &a, int n) {
    if (i == n) {
        return abs((sm - cur) - cur);
    }
    return min(solve(i + 1, cur + a[i], sm, a, n), solve(i + 1, cur, sm, a, n));
}

int main()
{
    fast_io();
    int n;
    cin >> n;
    vll c(n);
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sm += c[i];
    }

    cout << solve(0, 0, sm, c, n);
    return 0;
}
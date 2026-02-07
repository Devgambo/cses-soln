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

ll ipow(ll base, int exp) {
    ll result = 1;
    for (int i = 0; i < exp; ++i) result *= base;
    return result;
}


ll f(ll n, ll ans, map<ll, ll> mp){
    if(n<=0)
        return ans;
    auto it = mp.upper_bound(n);
    it--;
    ll lwlm = it->first;
    return f(n-lwlm, ans + mp[lwlm], mp);
}

int main() {
    fast_io();

    map<ll, ll> mp;
    for (int i = 0; i <= 20; i++) {
        ll key = ipow(3, i);
        ll value = ipow(3, i + 1);
        if (i > 0) value += i * ipow(3, i - 1);
        mp[key] = value;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout<<f(n,0,mp);
        cout<<endl;
    }

    return 0;
}
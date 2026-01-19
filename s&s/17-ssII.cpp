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
    int n;
    ll x;
    cin >> n >> x;
    map<ll,int> mp;
    ll ans = 0 ;
    mp[0]++;
    ll ttlsm = 0;
    for(int i=0; i<n; i++){
        ll ele;
        cin >> ele;
        ttlsm += ele;
        if(mp.count(ttlsm - x)){
            ans += mp[ttlsm - x];
        }
        mp[ttlsm]++;
    }
    

    cout << ans;
    return 0;
}


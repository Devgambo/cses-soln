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
    int n,m;
    cin >> n >> m;
    ll c[n], t[m];
    for(ll &i:c)   cin >> i;
    for(ll &i:t)   cin >> i;

    sort(t,t+m);
    ll ans = 0;
    for(ll i:c){
        auto clsu = lower_bound(t,t+m,i);
        ll closestTower = LINF;
        
        if(clsu != t+m){
            closestTower = min(closestTower, abs(i - *clsu));
        }
        if(clsu != t){
            closestTower = min(closestTower, abs(i - *(clsu-1)));
        }
        
        ans = max(ans, closestTower);
    }
    cout << ans;

    return 0;
}
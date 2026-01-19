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
    cin >> n;
    vector<pll> t;
    for(int i=0; i<n; i++){
        ll a, b;
        cin >> a >> b;
        t.push_back({a, b});
    }

    sort(t.begin(), t.end()); // sorts by duration, then deadline

    ll ans = 0;
    ll time = 0;
    for(auto& [duration, deadline] : t){
        time += duration;
        ans += (deadline - time);
    }

    cout << ans;
    return 0;
}
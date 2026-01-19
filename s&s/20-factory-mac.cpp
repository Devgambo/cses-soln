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

vll mac;
int n;
ll t;

bool bb(ll time){
    ll cnt = 0;
    for(ll i : mac){
        cnt += (time / i);
        if (cnt >= t) return true;
    }

    return (cnt >= t);
}
int main() {
    fast_io();
    cin >> n >> t;

    mac.resize(n);

    for(int i=0; i<n; i++) cin >> mac[i];
    ll low = 1;
    ll high = (ll)t * (*min_element(mac.begin(), mac.end()));
    ll ans = high;

    while(low <= high){
        ll mid = (low + (high - low)/2);
        if(bb(mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
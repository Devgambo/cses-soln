#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
#define pb push_back
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll x,y;
        cin >> x >> y;
        vll a(n);
        int tobe = 0; //index where money is going
        ll best = LLONG_MIN;
        for(int i=0; i<n; i++){
            cin >> a[i];
            ll val = (a[i]%x) + ((a[i]/x)*((x-y))); // max remainder + maximum transfer cost
            if(val > best){
                best = val;
                tobe = i;
            }
        }

        ll ans = a[tobe];
        for(int i=0; i<n; i++){
            if(i!=tobe){
                ll can_go = a[i]/x;
                ans += can_go * y; 
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
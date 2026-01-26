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
    int q;
    cin >> q; 
    for(int i=0 ; i<q; i++){
        ll c, m, x;
        cin >> c >> m >> x;
        ll n = c+m+x;
        ll l = 0;
        ll h = (n)/3 + 1;
        while(l+1 < h){
            ll mid = (l+h)/2;
            if(mid <= c && mid <= m && 3*mid <= n){
                l = mid;
            }else{
                h = mid;
            }                                                                                                    
        }

        cout << l <<'\n';
    }   
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vc = vector<char>;
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
    vll a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    vll ans;
    ans.pb(a[0]);

    for(int i=1; i<n; i++){
        if(ans.back() < a[i]){
            ans.pb(a[i]);
        }else{
            auto it = lower_bound(ans.begin(), ans.end(), a[i]);
            *it = a[i];
        }
    }

    cout << ans.size();
    return 0;
}




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
#define pb push_back
#define ff first
#define ss second
const int MOD = 998244353;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vi A(n);
    vi B(m);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    for(int i=0; i<m; i++){
        cin >> B[i];
    }
    ll ans = 0; 

    for(int i:A){
        for(int j:B){
            ans += abs(i-j) % MOD;
        }
    }
    // ll ans1 = 0; 
    // ll ans2 = 0; 

    // for(int i:A){
    //     ans1 += i;
    // }

    // ans1 = (ans1*m)% MOD;

    // for(int i:B){
    //     ans2+= i;
    // }
    // ans2 = ( ans2*n)%MOD;
    
    // ans = (ans1-ans2) % MOD;

    cout << ans%MOD;

    return 0;
}
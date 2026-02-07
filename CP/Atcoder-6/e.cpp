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
    vi a(n);
    vi b(n);
    vector<pair<int,int>> mp;
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
        mp.push_back({a[i],b[i]});
    }

    int maxi = 0;
    vi dp(n,0);
    for(int i=0; i<n; i++){

    }
    
    



    return 0;
}
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

ll modexp(int b, int p){
    if(p==0)    return 1;
    if(p==1)    return b;

    ll hf = modexp(b,p/2);
    if(p%2==1){
        return (hf*hf*b)%MOD;
    }else{
        return (hf*hf)%MOD;
    }
}

int main() {
    fast_io();
    ll n;
    cin >> n;
    ll rel = modexp(2,n);
    cout<< rel % MOD;
    return 0;
}
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

void f(int k , int x){
    int ans = x;
    while(k>0){
        ans*=2;
        k--;
    }
    cout<<ans;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int k,x;
        cin >> k>> x;
        f(k,x);
        cout<<endl;
    }

    return 0;
}
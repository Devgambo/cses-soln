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

void f(int n, vll a){
    
    ll mn = LONG_LONG_MAX;
    ll smn = LONG_LONG_MAX;

    for (ll x : a) {
        if (x < mn) {
            smn = mn;
            mn = x;
        } else if (x > mn && x < smn) {
            smn = x;
        }
    }

    ll k = mn;

    while(smn - mn > k ){
        k++;
    }
    cout << k <<endl;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t > 0)
    {
        t--;
        int n;
        cin >> n;
        vll a(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        f(n,a);
    }


    return 0;
}
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
#define n endl

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

//loop 0 - 2^(n) - 1;
//greycode = i ^ (i>>1);


int main()
{
    fast_io();
    ll n;
    cin >> n;
    ll total = 1LL << n;
    for (ll i = 0; i < total; ++i)
    {
        ll gray = i ^ (i >> 1);
        string s;
        for (ll j = n - 1; j >= 0; --j)
        {
            s += ((gray >> j) & 1) ? '1' : '0';
        }
        cout << s << '\n';
    }

    return 0;
}
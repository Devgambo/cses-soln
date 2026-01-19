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

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void fun(ll a, ll b)
{
    bool ans = false;

    // Correct logic for Coin Piles problem
    if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return;
}

int main()
{
    fast_io();
    ll t;
    cin >> t;
    while (t > 0)
    {
        t--;
        ll a, b;
        cin >> a >> b;
        fun(a, b);
    }
    return 0;
}
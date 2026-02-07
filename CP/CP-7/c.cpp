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

void f(ll a, ll b)
{
    ll ans = -1;
    for (ll k = 1; k * k <= b; k++)
    {
        if (b % k != 0)
            continue;

        __int128 val = (__int128)a * k + b / k;
        if (val % 2 == 0)
            ans = max(ans, (ll)val);

        // check b/k
        ll d = b / k;
        if (k != d)
        {
            __int128 val = (__int128)a * d + b / d;
            if (val % 2 == 0)
                ans = max(ans, (ll)val);
        }
    }

    cout << ans;
    return;
}

int main()
{
    fast_io();
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        f(a, b);
        cout << endl;
    }

    return 0;
}
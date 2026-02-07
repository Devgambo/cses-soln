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

int main()
{
    fast_io();
    int t;
    cin >> t;
    while (t--)
    {
        ll s, k, m;
        cin >> s >> k >> m;
        if (m == k)
        {
            cout << min(s, k) << endl;
        }
        else if (m < k)
        {
            if (s - m > 0)
            {
                cout << s - m << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {
            if (k >= s)
            {
                if (m % k >= s)
                {
                    cout << 0 << endl;
                }
                else
                {
                    cout << s - (m % k) << endl;
                }
            }
            else
            {
                ll val = m % k;
                int mul = m / k;
                if (mul % 2 == 0)
                {
                    cout << s - val << endl;
                }
                else
                {
                    cout << k - val << endl;
                }
            }
        }
    }

    return 0;
}
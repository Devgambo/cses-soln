#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using vpll = vector<pll>;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second

#define debug(x) cerr << #x << " = " << (x) << endl

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
        int n;
        cin >> n;
        vll a(n);
        ll mini = 1e18, maxi = 0;
        int issorted = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i > 0 && a[i] < a[i - 1])
                issorted = 0;
            mini = min(mini, a[i]);
            maxi = max(maxi, a[i]);
        }
        if (issorted)
        {
            cout << -1 << '\n';
            continue;
        }

        ll ans = 1e18;
        vll b = a;
        sort(all(a));
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                ll cur = max(a[i] - mini, maxi - a[i]);
                ans = min(ans, cur);
            }
        }
        cout << ans;
        cout << '\n';
    }
    return 0;
}
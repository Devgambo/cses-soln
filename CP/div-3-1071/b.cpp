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

void f(int n, vi a)
{
    vi b;
    int ans = INT_MAX;
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        int dif = a[i] - a[i - 1];
        b.push_back(dif);
        sum += abs(dif);
    }

    vector<pair<int, int>> b2;
    for (int i = 1; i < n - 1; i++)
    {
        int dif = abs(b[i] + b[i - 1]);
        int sm = abs(b[i]) + abs(b[i - 1]);
        b2.push_back({dif, sm});
    }

    ans = min({sum , sum  - abs(b[0]), sum  - abs(b[n - 2])});

    for (auto i : b2)
    {
        int ans2 = sum - i.second + abs(i.first);
        ans = min(ans, ans2);
    }

    cout << ans << endl;
}

int main()
{
    fast_io();
    int t;
    cin >> t;

    while (t > 0)
    {
        t--;
        int n;
        cin >> n;
        vi a(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        f(n,a);
    }

    return 0;
}
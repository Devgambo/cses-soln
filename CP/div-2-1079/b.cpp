#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
#define pb push_back
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fast_io();

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vi p(n), a(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        unordered_set<int> used;
        bool pos = true;

        used.insert(a[0]);

        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                if (used.count(a[i])) {
                    pos = false;
                    break;
                }
                used.insert(a[i]);
            }
        }

        if (!pos) {
            cout << "NO\n";
            continue;
        }

        vi b;
        b.pb(a[0]);
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1])
                b.pb(a[i]);
        }
        int j = 0;
        for (int i = 0; i < n && j < (int)b.size(); i++) {
            if (p[i] == b[j])   j++;
        }

        if (j == (int)b.size())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
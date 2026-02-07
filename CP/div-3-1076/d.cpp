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

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


int main() {
    fast_io();
    int t;
    cin >> t;
    while(t--){
        int n;  cin >> n;
        vll a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        vi b(n);
        vll prefixSum(n+1, 0);
        for(int k=0; k<n; k++)  {
            cin >> b[k];
            prefixSum[k+1] = prefixSum[k] + b[k];
        }

        sort(all(a));
        ll ans = 0;
        
        for(int i=0; i<n; i++){
            ll x = a[i];
            ll numSwords = n - i;
            ll level = upper_bound(all(prefixSum), numSwords) - prefixSum.begin() - 1;
            ans = max(ans, x * level);
        }
        
        cout << ans << '\n';
    }
    return 0;
}
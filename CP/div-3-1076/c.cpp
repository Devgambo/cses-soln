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
        int n,q;  cin >> n >> q;
        vi a(n);
        vi b(n);
        for(int i=0; i<n; i++)  cin >> a[i];
        for(int i=0; i<n; i++)  cin >> b[i];
        
        vi maxVal(n);
        maxVal[n-1] = max(a[n-1], b[n-1]);
        for(int i = n-2; i >= 0; i--){
            maxVal[i] = max({a[i], b[i], maxVal[i+1]});
        }
        
        vi presm(n+1, 0);
        for(int i=0; i<n; i++){
            presm[i+1] = presm[i] + maxVal[i];
        }

        for(int i=0; i<q; i++){
            int l,r; cin >> l >> r;
            cout << presm[r]-presm[l-1] <<" ";
        }
        cout << '\n';
    }
    return 0;
}
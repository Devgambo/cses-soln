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
        vi ans(n+1);
        ans[n] = n;
        ans[n-1] = 1;
        int fg = 1;
        for(int i=n-2; i>=1; i--){
            if(fg){
                fg=0;
                ans[i] = i + ans[i+1];
            }else{
                fg=1;
                ans[i] = ans[i+1] - i;
            }
        }

        for(int i=1; i<=n; i++) cout << ans[i] << " ";

        cout << '\n';
    }
    return 0;
}
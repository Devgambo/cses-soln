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
        pair<ll,int> mini = {1e18,0};
        pair<ll,int> maxi = {-1e18,0};
        for(int i=0; i<n; i++){
            ll x;
            cin >> x;
            a[i] = x;
            if(mini.ff > x){
                mini = {x,i};
            }
            if(maxi.ff <= x){
                maxi = {x,i};
            }
        }
        ll ans = 1e18;
        // for(int i = mini.ss; i<n; i++){
        //     if(a[i] == mini.ff) continue;
        //     ans = min(ans, abs(a[i] - mini.ff));
        // }
        // for(int i = 0; i<=maxi.ss; i++){
        //     if(a[i] == maxi.ff) continue;
        //     ans = min(ans, abs(a[i] - maxi.ff));
        // }
        for(int i = maxi.ss; i<n; i++){
            if(a[i] == maxi.ff) continue;
            ans = min(ans, abs(a[i] - maxi.ff));
        }
        if(ans == 1e18){
            cout << -1;
        }else{
            cout << ans;
        }
        cout << '\n';
    }
    return 0;
}
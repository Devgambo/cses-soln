#include <bits/stdc++.h>
using namespace std;

// Type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vpii = vector<pii>;

// Constants
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);

// Macros for container operations
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second

// Loop macros
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i >= (b); i--)
#define trav(a, x) for(auto& a : x)

// Utility macros
#define endl '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

// Debugging
#define debug(x) cerr << #x << " = " << (x) << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// DP + BS

int main() {
    fast_io();
    int n;
    cin >> n;
    vll dp(n);
    vll t;
    for(int i=0; i<n; i++){
        ll tm;
        cin >> tm;
        t.pb(tm);
        
        int t2 = upper_bound(all(t), tm-90) - t.begin() - 1;
        int t3 = upper_bound(all(t), tm-1440) - t.begin() - 1;
        
        dp[i] = (i?dp[i-1]:0) + 20;
        dp[i] = min(dp[i], (t2>=0?dp[t2]:0) + 50);
        dp[i] = min(dp[i], (t3>=0?dp[t3]:0) + 120);
        
        cout << (dp[i] - (i?dp[i-1]:0))<<endl;
    }
    return 0;
}
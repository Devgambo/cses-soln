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

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i >= (b); i--)
#define trav(a, x) for(auto& a : x)

#define endl '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

#define debug(x) cerr << #x << " = " << (x) << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vvi adj;
int diameter = 0;

int dfs(int u, int p){
    int max1 = 0, max2 = 0;
    
    for(int v : adj[u]){
        if(v == p) continue;
        int depth = dfs(v, u) + 1;
        
        // Track two largest depths
        if(depth > max1){
            max2 = max1;
            max1 = depth;
        } else if(depth > max2){
            max2 = depth;
        }
    }
    
    // Update diameter: sum of two longest paths through this node
    diameter = max(diameter, max1 + max2);
    
    // Return the longest path from this node
    return max1;
}

int main() {
    fast_io();
    int n;
    cin >> n;
    adj.resize(n+1);
    for(int i=0; i<n-1; i++){
        int x,y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 0);
    cout << diameter << endl;

    return 0;
}
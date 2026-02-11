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

#define debug(x) cerr << #x << " = " << (x) << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int n, q;
const int LOG = 20; // 2^20 > 200000
vvi adj;
vvi parent;
vi depth;

void dfs(int u, int p, int d) {
    parent[0][u] = p;
    depth[u] = d;
    
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u, d + 1);
        }
    }
}

void precompute() {
    // Fill binary lifting table
    for(int i = 1; i < LOG; i++) {
        for(int j = 1; j <= n; j++) {
            if(parent[i-1][j] != -1) {
                parent[i][j] = parent[i-1][parent[i-1][j]];
            }
        }
    }
}

int lca(int a, int b) {
    // Make sure a is deeper or equal
    if(depth[a] < depth[b]) swap(a, b);
    
    int diff = depth[a] - depth[b];
    for(int i = 0; i < LOG; i++) {
        if(diff & (1 << i)) {
            a = parent[i][a];
        }
    }
    
    if(a == b) return a;
    
    for(int i = LOG - 1; i >= 0; i--) {
        if(parent[i][a] != parent[i][b]) {
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    
    return parent[0][a];
}


void dfs_presm(vi &values, int nd, int par){
    int x = values[nd];
    for(int i:adj[nd]){
        if(i!=par){
            dfs_presm(values, i, nd);
            x += values[i];
        }
    }
    values[nd] = x;
    return;
}

int main() {
    fast_io();
    cin >> n >> q;
    
    adj.resize(n + 1);
    parent.assign(LOG, vi(n + 1, -1));
    depth.resize(n + 1);
    
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    dfs(1, -1, 0);
    precompute();

    //we'll use diff
    vi values(n+1,0);
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        int Lca = lca(x,y);
        values[x] += 1;
        values[y] += 1;
        values[Lca] -= 1;
        int P_Lca = parent[0][Lca];
        if(P_Lca != -1){
            values[P_Lca] -= 1; 
        }
    }

    dfs_presm(values, 1, -1);
    for(int i=1; i<=n; i++){  cout << values[i] <<" ";}
    
    return 0;
}
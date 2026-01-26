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

#define debug(x) cerr << #x << " = " << (x) << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int n, m;

bool dfs(vi &vis, const vvi &g, int i, int color, int parent){
    vis[i] = color;
    int nextColor = (color == 1) ? 2 : 1;
    
    for(int node : g[i]){
        if(node == parent) continue; // Skip parent in undirected graph
        
        if(!vis[node]){
            if(!dfs(vis, g, node, nextColor, i))
                return false;
        } else {
            // Already visited - check if same color (not bipartite)
            if(vis[node] == color){
                return false;
            }
        }
    }
    return true;
}


int main() {
    fast_io();
    cin >> n >> m;
    vvi g(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    vi vis(n+1, 0);
    
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(!dfs(vis, g, i, 1, -1)){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << vis[i] << " ";
    }
    cout << '\n';

    return 0;
}
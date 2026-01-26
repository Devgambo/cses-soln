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
int cycleStart = -1, cycleEnd = -1;
bool dfs(vi &vis, vi &par, const vvi &g, int i){
    vis[i] = 1;
    for(int node : g[i]){
        if(vis[node] == 1){
            // Found a cycle (back edge to a node in current path)
            cycleEnd = i;
            cycleStart = node;
            return true;
        }
        
        if(vis[node] == 0){
            par[node] = i;
            if(dfs(vis, par, g, node))
                return true;
        }
    }
    vis[i] = 2; // Mark as completely processed
    return false;
}


int main() {
    fast_io();
    cin >> n >> m;
    vvi g(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
    }

    vi par(n+1, -1);
    vi vis(n+1, 0); // 0 = unvisited, 1 = in current path, 2 = fully processed
    
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(vis, par, g, i)){
                // Reconstruct cycle
                vi cycle;
                cycle.pb(cycleStart);
                for(int v = cycleEnd; v != cycleStart; v = par[v]){
                    cycle.pb(v);
                }
                cycle.pb(cycleStart);
                
                cout << cycle.size() << '\n';

                reverse(cycle.begin(), cycle.end());
                for(int c : cycle){
                    cout << c << " ";
                }
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
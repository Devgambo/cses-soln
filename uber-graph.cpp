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

// ques : given no of nodes and 2 vectors a and b showing a bidirectional connection from a[i] to b[i], we have to return a int showing min unreachable nodes we can achieve after converting bidirectional edge to any one direction.


//key-realisation: if there's a cycle in a path we can orient it such that all the nodes are reachable.
bool hasCycle;

void dfs(int nd, vvi &g, int par, vi &vis){
    vis[nd] = 1;
    for(int neighbor : g[nd]){
        if(!vis[neighbor]){
            dfs(neighbor, g, nd, vis);
        } else if(neighbor != par){
            // Found a back edge - cycle exists
            hasCycle = true;
        }
    }
}

int minunreachable(int n, vi a, vi b){
    vvi g(n+1);
    for(int i=0; i<a.size(); i++){
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
    }

    int ans = 0;
    vi vis(n+1, 0);
    
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            hasCycle = false;
            dfs(i, g, -1, vis);
            if(!hasCycle){
                ans++;
            }
        }
    }

    return ans;
}



int main() {
    fast_io();
    int n = 6;
    vi from = {1,2,4,5,4};
    vi to = {2,3,5,6,6};

    int ans = minunreachable(n,from,to);

    cout << ans;
    return 0;
}
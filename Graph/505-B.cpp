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


vector<vpii> g;

bool dfs(int a, int b, int color, vi &vis){
    if(a == b){
        return true;
    }
    vis[a] = 1;
    for(auto [nxt, col] : g[a]){
        if(!vis[nxt] && col == color) {
            if(dfs(nxt, b, color, vis)) {
                return true;
            }
        }
    }
    return false;
}


int main() {
    fast_io();
    int n, m ;
    cin >>n >> m;
    g.resize(n+1);
    for(int i=0; i<m; i++){
        int a , b, c;
        cin >> a >> b >> c;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }
    int q; cin >> q;
    for(int i=0; i<q; i++){
        int u, v;
        cin >> u >> v;
        int count = 0;
        // Check connectivity for each color from 1 to m
        for(int color = 1; color <= m; color++){
            vi vis(n+1, 0);
            if(dfs(u, v, color, vis)){
                count++;
            }
        }
        cout << count << '\n';
    }   
    return 0;
}
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


void dfs(int nd, const vvi &g, vi &vis){
    vis[nd] =1;
    for(int i:g[nd]){
        if(!vis[i]){
            dfs(i,g,vis);
        }
    }
}

int n, m;
int main() {
    fast_io();
    cin >> n >> m;
    vvi g(n+1);
    vvi revg(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        g[a].pb(b); 
        revg[b].pb(a); 
    }

    // Check 1: Can we reach all cities from city 1? (forward)
    vi vis1(n+1, 0);
    dfs(1, g, vis1);
    for(int i = 1; i <= n; i++){
        if(!vis1[i]){
            cout << "NO" << '\n';
            cout << 1 << " " << i;  // Can't go from 1 to i
            return 0;
        }
    }
    
    // Check 2: Can we reach city 1 from all cities? (reverse)
    vi vis2(n+1, 0);
    dfs(1, revg, vis2);
    for(int i = 1; i <= n; i++){
        if(!vis2[i]){
            cout << "NO" << '\n';
            cout << i << " " << 1;  // Can't go from i to 1
            return 0;
        }
    }

    cout << "YES" << '\n';


    return 0;
}
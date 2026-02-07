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

// dp[node][0]: Maximum matching in the subtree of node where node is NOT matched to its parent
// dp[node][1]: Maximum matching in the subtree of node where node IS matched to one of its children

vvi dp;
vvi adj;
void dfs(int v, int par){
    dp[v][0]=0;
    dp[v][1]=0;

    //not taking v;
    int sm = 0;
    for(int u:adj[v]){
        if(u==par)  continue;
        dfs(u,v);
        sm += max(dp[u][0], dp[u][1]);
    }
    dp[v][0] = sm;


    // taking v;
    ll best=0 ;
    for(int u:adj[v]){
        if(u==par)  continue;
        ll tmp = 1 + dp[u][0] + (sm - max(dp[u][0], dp[u][1]));
        best = max(best, tmp);
    }
    dp[v][1] = best;
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
    dp.resize(n+1, vi(2,0));

    dfs(1,0);

    cout << max(dp[1][0], dp[1][1]);
    return 0;
}
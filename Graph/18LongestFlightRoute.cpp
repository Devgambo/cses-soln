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

int n, m;

int main() {
    fast_io();
    cin >> n >> m;
    vector<vi> g(n+1);
    vi indeg(n+1,0);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        indeg[b]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    vi topo;
    while(!q.empty()){
        int nd = q.front(); q.pop();
        topo.pb(nd);
        for(int i:g[nd]){
            indeg[i]--;
            if(indeg[i]==0) q.push(i);
        }
    }

    vi dp(n+1,0);  // dp[i] : longest route to reach i form 1;
    vi parent(n+1,-1);  // track parent for path reconstruction
    dp[1] = 1;
    for(int i:topo){
        if(dp[i] == 0) continue;  // skip unreachable nodes
        for(int j: g[i]){
            if(dp[j] < dp[i] + 1){
                dp[j] = dp[i] + 1;
                parent[j] = i;
            }
        }
    } 

    if(dp[n] == 0){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dp[n] << '\n';
    vi path;
    int curr = n;
    while(curr != -1){
        path.pb(curr);
        curr = parent[curr];
    }

    reverse(all(path));

    for(int i:path) cout << i << " ";
    return 0;
}
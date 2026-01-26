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
    vector<vpll> g(n+1);
    for(int i=0; i<m; i++){
        ll a,b;
        ll c;
        cin >> a >> b >> c;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }

    // min spanning tree ----> Prims algo.

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,1});
    vi vis(n+1,0);
    ll minsm = 0;
    int cnt = 0;
    while(!pq.empty()){
        auto [wt, nd] = pq.top(); pq.pop();
        if(vis[nd]==1) continue;

        vis[nd] = 1;
        cnt++;
        minsm += wt;
        for(auto it:g[nd]){
            if(!vis[it.ff]){
                pq.push({it.ss, it.ff});
            }
        }
    }

    if(cnt == n){
        cout << minsm << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
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

int main() {
    fast_io();
    cin >> n >> m;
    vector<vpii> g(n+1);
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].pb({b,c});
    }

    //shortest path from 1 to all
    vll dist(n+1, 1e18);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        auto [dis, nd] = pq.top();  pq.pop();
        
        // Skip if we already found a better path
        if(dis > dist[nd]) continue;
        
        for(auto i:g[nd]){
            int nxnd = i.ff;
            ll wt = i.ss;
            if(dis + wt < dist[nxnd]){
                dist[nxnd] = dis + wt;
                pq.push({dist[nxnd], nxnd});
            }
        }
    }

    for(int i=1; i<=n; i++) cout << dist[i] << " ";
    
    return 0;
}
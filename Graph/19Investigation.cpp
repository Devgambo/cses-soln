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
        ll a,b,c;
        cin >> a >> b >> c;
        g[a].pb({b,c});
    }

    // Dijkstra with 4 arrays
    vll dist(n+1, LINF);
    vll ways(n+1, 0);
    vi minEdges(n+1, 0);
    vi maxEdges(n+1, 0);
    
    priority_queue<pll, vpll, greater<pll>> pq;
    
    dist[1] = 0;
    ways[1] = 1;
    minEdges[1] = 0;
    maxEdges[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto [v, w] : g[u]){
            ll newDist = dist[u] + w;
            
            if(newDist < dist[v]){
                // Found shorter path
                dist[v] = newDist;
                ways[v] = ways[u];
                minEdges[v] = minEdges[u] + 1;
                maxEdges[v] = maxEdges[u] + 1;
                pq.push({newDist, v});
            }
            else if(newDist == dist[v]){
                // Found another path with same distance
                ways[v] = (ways[v] + ways[u]) % MOD;
                minEdges[v] = min(minEdges[v], minEdges[u] + 1);
                maxEdges[v] = max(maxEdges[v], maxEdges[u] + 1);
            }
        }
    }
    
    cout << dist[n] << " " << ways[n] << " " << minEdges[n] << " " << maxEdges[n] << "\n";
    return 0;
}
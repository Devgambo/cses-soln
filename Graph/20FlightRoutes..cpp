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
int k;
int main() {
    fast_io();
    cin >> n >> m >> k;
    vector<vpll> g(n+1);
    for(int i=0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        g[a].pb({b,c});
    }

    vector<priority_queue<ll>> dist(n+1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,1});
    
    while(!pq.empty()){
        auto [wt, nd] = pq.top();
        pq.pop();
        
        if(dist[nd].size() >= k && wt >= dist[nd].top()) continue;
        
        dist[nd].push(wt);
        if(dist[nd].size() > k) dist[nd].pop();
        
        for(auto [nxnd, cost] : g[nd]){
            ll newd = wt + cost;
            
            if(dist[nxnd].size() < k || newd < dist[nxnd].top()){
                pq.push({newd, nxnd});
            }
        }
    }

    vll ans;
    while(!dist[n].empty()){
        ans.pb(dist[n].top());
        dist[n].pop();
    }
    
    reverse(all(ans));
    for(ll x : ans) cout << x << " ";
    cout << '\n';

    return 0;
}
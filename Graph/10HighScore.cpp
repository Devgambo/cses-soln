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
using vvll = vector<vll>;
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
    vector<tuple<int,int,ll>> g;
    for(int i=0; i<m; i++){
        int a,b;
        ll x;
        cin >> a >> b >> x;
        g.pb({a,b,x});
    }

    //negative weights => Bellman ford (maximize instead of minimize)
    vll dist(n+1,-1e18);
    dist[1] = 0;

    // Relax edges n-1 times
    for(int i=0; i<n-1; i++){
        for(auto [a,b,x]:g){
            if(dist[a]!=-1e18){
                dist[b] = max(dist[b], x+dist[a]);
            }
        }
    }
    
    // Detect nodes affected by positive cycles
    vector<bool> affected(n+1, false);
    for(int i=0; i<n; i++){
        for(auto [a,b,x] : g){
            if(dist[a]!=-1e18 && dist[b] < dist[a] + x){
                dist[b] = dist[a] + x;
                affected[b] = true;
            }
            if(affected[a]) affected[b] = true;
        }
    }
    
    if(affected[n]){
        cout << -1 << '\n';
    } else {
        cout << dist[n] << '\n';
    }
    return 0;
}
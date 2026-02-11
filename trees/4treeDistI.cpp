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

vvi adj;
vi end1,end2;
vi distRoot;


int bfs(int srt, vi &dist){             //returns the fartest node
    queue<int> q;
    q.push(srt);
    dist[srt] = 0;
    pii m = {0,0};
    while(!q.empty()){
        int nd = q.front(); q.pop();
        for(int i:adj[nd]){
            if(dist[nd]+1 < dist[i]){
                dist[i] = dist[nd] + 1;
                q.push(i);
                if(m.ss < dist[i]){
                    m = {i,dist[i]};
                }
            }
        }
    }

    return m.ff;
}


int main() {
    fast_io();
    int n;
    cin >> n;
    adj.resize(n+1);

    if(n==1){
        cout << 0;
        return 0;
    }

    for(int i=0; i<n-1; i++){
        int x,y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    distRoot.resize(n+1,1e9);
    end1.resize(n+1,1e9);
    end2.resize(n+1,1e9);

    int e1 = bfs(1,distRoot);
    int e2 = bfs(e1,end1);
    bfs(e2, end2);

    vi ans(n+1,0);

    for(int i=1; i<=n; i++){
        ans[i] = max(end1[i], end2[i]);
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}
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
    }


    //dikstar with dp(state)
    //dist[node][1] =  discount used.  
    //dist[node][0] =  discount still there.
    vector<vll> dist(n+1, vll(2, LINF));
    dist[1][0] = 0;

    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<>> pq;
    pq.push({0,1,0});   // cost, node, state [state - 0: left, -1:used]
    
    while(!pq.empty()){
        auto [curdist, node, used] = pq.top(); pq.pop();

        if(curdist > dist[node][used])  continue;

        for(auto [nx, nwt] : g[node]){
            if(used == 0){
                //go to next node w/o using disc
                if(dist[node][0] + nwt  < dist[nx][0]){
                    dist[nx][0] = dist[node][0] + nwt;
                    pq.push({dist[nx][0], nx, 0});
                }

                //use disc
                if(dist[node][0] + nwt / 2 < dist[nx][1]){
                    dist[nx][1] = dist[node][0] + nwt/2;
                    pq.push({dist[nx][1], nx, 1});
                }
            }
            else{
                //dont have disc
                if(dist[node][1] + nwt  < dist[nx][1]){
                    dist[nx][1] = dist[node][1] + nwt;
                    pq.push({dist[nx][1], nx, 1});
                }
            }
        }
    }

    cout << dist[n][1] << endl;
    return 0;
}
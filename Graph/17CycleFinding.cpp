
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
        ll c;
        cin >> a >> b >> c;
        g.pb({a,b,c});
    }


    //we'hv init all the nodes as 0 so we can treat all the nodes as origin and 
    //not only 1 since there are cycles which are unreachable from 1.

    vll dist(n+1,0);
    vi par(n+1,-1);
    
    for(int i=0 ; i<n-1 ; i++){
        for(auto [a,b,c] : g){
            if(dist[a] + c < dist[b]){
                dist[b] = dist[a] + c;
                par[b] = a;
            }
        }
    }


    //check for negative cycle and find a node in it
    int cycNode = -1;
    for(auto [a,b,c] : g){
        if(dist[a] + c < dist[b]){
            cycNode = b;
            par[b] = a;
            break;
        }
    }


    if(cycNode == -1){
        cout << "NO\n";
    }else{ 
        // Move back n steps to ensure we're actually in the cycle
        for(int i = 0; i < n; i++){
            cycNode = par[cycNode];
        }
        
        cout <<"YES"<<'\n';
        vi cycle;
        int curr = cycNode;
        do {
            cycle.pb(curr);
            curr = par[curr];
        } while(curr != cycNode);
        cycle.pb(cycNode);
        
        reverse(all(cycle));
        for(int i : cycle) cout << i << " ";
        cout << '\n';
    }
    
    return 0;
}
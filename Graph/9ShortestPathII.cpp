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

int n, m, q;
int main() {
    fast_io();
    cin >> n >> m >> q;
    vector<vll> dist(n+1, vll(n+1,1e18));
    
    // Initialize diagonal to 0
    for(int i=1; i<=n; i++){
        dist[i][i] = 0;
    }
    
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b] , (ll)c);
        dist[b][a] = min(dist[b][a] , (ll)c);
    }
    vpii qry;
    for(int i=0; i<q; i++){
        int a,b;    cin >> a >> b;
        qry.pb({a,b});
    }


    //Wershall folyd
    for(int via=1; via <= n; via++){
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                dist[i][j] = min(dist[i][j], (ll)(dist[i][via] + dist[via][j]));
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(dist[i][j]==1e18){
                dist[i][j] = -1;
            }
        }
    }

    for(auto i:qry){
        int a = i.ff;
        int b = i.ss;
        cout << dist[a][b] << endl;
    }

    return 0;
}
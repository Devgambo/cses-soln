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
vi x = {-1,0,1,0};
vi y = {0,1,0,-1};

void dfs(const vector<vector<char>>& g,  int i, int j, vvi &vis){
    vis[i][j] = 1;
    for(int k=0; k<4; k++){
        int nx = i+ x[k];
        int ny = j+ y[k];
        if(nx < n && nx >=0  && ny<m && ny>=0){
            if(g[nx][ny] == '.' && !vis[nx][ny]){
                dfs(g,nx,ny,vis);
            }
        }
    }
}



int main() {
    fast_io();
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> g[i][j];
        }
    }

    vvi vis(n, vi(m,0));
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(g[i][j]=='.' && !vis[i][j]){
                dfs(g,i,j,vis);
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
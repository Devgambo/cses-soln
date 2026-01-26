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
vi dx = {-1, 1, 0, 0};
vi dy = {0, 0, -1, 1};
string dir = "UDLR";

int main() {
    fast_io();
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    int si=0, sj=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> g[i][j];
            if(g[i][j] == 'A'){
                si = i;
                sj = j;
            }
        }
    }

    vvi vis(n, vi(m,0));
    vvi dir_idx(n, vi(m, -1));
    
    queue<pii> q;
    q.push({si, sj});
    vis[si][sj] = 1;
    
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        
        for(int k=0; k<4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            // Bounds check FIRST
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if(g[nx][ny] == 'B'){
                cout << "YES" << '\n';
                vector<char> path;
                path.pb(dir[k]);
                int ci = i, cj = j;
                while(ci != si || cj != sj){
                    int d = dir_idx[ci][cj];
                    path.pb(dir[d]);
                    ci = ci - dx[d];
                    cj = cj - dy[d];
                }

                reverse(path.begin(), path.end());
                cout << path.size() << '\n' ;
                for(char c : path) cout<<c;
                cout << '\n';
                return 0;
            }
            
            if(g[nx][ny] != '#' && !vis[nx][ny]){
                vis[nx][ny] = 1;
                dir_idx[nx][ny] = k;
                q.push({nx, ny});
            }
        }
    }

    cout << "NO" << '\n';
    return 0;
}
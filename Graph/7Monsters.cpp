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
vector<vector<char>> g;
string dir = "UDLR";
bool isValid(int i, int j){
    return i>=0 && i<n && j>=0 && j<m && g[i][j]!='#';
}

int main() {
    fast_io();
    cin >> n >> m;
    g.resize(n, vector<char>(m));
    vvi monstertime(n, vi(m,-1));
    int si=0, sj=0;
    queue<pii> mon;
    vvi vism(n, vi(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> g[i][j];
            if(g[i][j] == 'A'){
                si = i;
                sj = j;
            }
            
            //for multisource bsf
            if(g[i][j] == 'M'){
                mon.push({i,j});
                vism[i][j] = 1;
            }
        }
    }


    //first find the monsters path time
    int time = 0;
    while(!mon.empty()){
        int sz = mon.size();
        while(sz--){
            auto [i,j] = mon.front(); mon.pop();
            monstertime[i][j] = time;
            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(isValid(nx, ny) && !vism[nx][ny]){
                    vism[nx][ny] = 1;
                    mon.push({nx,ny});
                }
            }
        }
        time++;
    }
    
    
    //Now we find the path
    queue<pii> q;
    vvi vis(n, vi(m,0));
    vvi dir_idx(n, vi(m, -1));

    q.push({si, sj});
    vis[si][sj] = 1;
    vvi dist(n, vi(m, -1));
    dist[si][sj] = 0;
    
    // Check if already at boundary
    if(si == 0 || si == n-1 || sj == 0 || sj == m-1){
        cout << "YES\n0\n\n";
        return 0;
    }

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        
        for(int k=0; k<4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            if(!isValid(nx, ny)) continue;
            
            // Check if we reached a boundary (escape point)
            if(nx == 0 || nx == n-1 || ny == 0 || ny == m-1){
                int newDist = dist[i][j] + 1;
                if(monstertime[nx][ny] == -1 || monstertime[nx][ny] > newDist){
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
            }
            
            int newDist = dist[i][j] + 1;
            if(!vis[nx][ny] && (monstertime[nx][ny] == -1 || monstertime[nx][ny] > newDist)){
                vis[nx][ny] = 1;
                dist[nx][ny] = newDist;
                dir_idx[nx][ny] = k;
                q.push({nx, ny});
            }
        }
    }

    cout << "NO" << '\n';
    return 0;
}
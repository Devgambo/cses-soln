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



int main() {
    fast_io();
    cin >> n >> m;
    vvi g(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    vi vis(n+1,0);
    vi par(n+1,0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    vi ans;
    while(!q.empty()){
        int cur = q.front();    q.pop();
        if(cur==n){
            while(cur!=1){
                ans.pb(cur);
                cur = par[cur];
            }
            ans.pb(1);
            reverse(all(ans));
        }

        for(int i:g[cur]){
            if(!vis[i]){
                par[i] = cur;
                vis[i] = 1;
                q.push(i);
            }
        }
    }



    if(ans.size()){
        cout << ans.size() << '\n';
        for(int i:ans)   cout << i << " ";
    }else{
        cout <<"IMPOSSIBLE";
    }

    return 0;
}
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
int n,q;
int LOG = 30; //2*(30) > 10^(9)
vvi dp;
//binary lifting
void precomputeDP(const vi &parents){
    for(int i=1; i<=n; i++){
        dp[0][i]=parents[i];
    }

    for(int i=1; i<LOG; i++){
        for(int j=1; j<=n; j++){
            if(dp[i-1][j] == -1){
                dp[i][j] = -1;  // Already at/past root
            } else {
                dp[i][j] = dp[i-1][dp[i-1][j]];
            }
        }
    }
}

void fun(int x, int k){
    int curr = x;
    for(int i=0; i<LOG; i++){
        if(curr == -1) break;  // Already reached root or beyond
        if(k & (1 << i)){
            curr = dp[i][curr];
        }
    }

    cout << curr;
}

int main() {
    fast_io();
    cin >> n >> q;
    vi parents(n+1,0);
    parents[1]=-1;
    for(int i=2; i<=n; i++){
        cin >> parents[i];
    }

    dp.resize(LOG, vi(n+1));
    
    precomputeDP(parents);

    for(int i=0; i<q; i++){
        int x,k;
        cin >> x >> k;
        fun(x, k);
        cout << '\n';
    }
    return 0;
}
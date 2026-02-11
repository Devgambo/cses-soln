#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvll = vector<vll>;
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


ll dist(ll x, ll y, ll Bx, ll By){
    if(y >= By){
        return (Bx - x) + (y - By);
    }else{
        return (Bx - x) + (By - y);
    }
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while(t--){
        int n;
        ll Ax, Ay, Bx, By;
        cin >> n >> Ax >> Ay >> Bx >> By;
        vll x(n), y(n);
        for(int i=0; i<n; i++) cin >> x[i];
        for(int i=0; i<n; i++) cin >> y[i];
        
        // Group by x coordinate using map
        map<ll, pair<ll,ll>> col; // col[x] = {ymin, ymax}
        for(int i=0; i<n; i++){
            if(col.find(x[i]) == col.end()){
                col[x[i]] = {y[i], y[i]};
            } else {
                col[x[i]].ff = min(col[x[i]].ff, y[i]);
                col[x[i]].ss = max(col[x[i]].ss, y[i]);
            }
        }
        
        // Extract sorted unique x coordinates
        vector<ll> xs;
        vector<ll> ymn, ymx;
        for(auto& [xval, p] : col){
            xs.pb(xval);
            ymn.pb(p.ff);
            ymx.pb(p.ss);
        }
        int m = xs.size();
        
        // dp[i][0] = min cost to finish column i at ymin
        // dp[i][1] = min cost to finish column i at ymax
        vvll dp(m, vll(2, LINF));
        
        // First column: start from (Ax, Ay), reach xs[0], cover [ymn[0], ymx[0]]
        ll hdist = xs[0] - Ax;
        ll range = ymx[0] - ymn[0];
        
        // End at ymax[0]
        dp[0][1] = hdist + abs(ymx[0] - Ay) + abs(ymn[0] - Ay) + range;
        // End at ymin[0]  
        dp[0][0] = hdist + abs(ymx[0] - Ay) + abs(ymn[0] - Ay) + range;
        
        // Simplified: cost = hdist + max(ymx[0], Ay) - min(ymn[0], Ay) + range
        // But we need to track where we end
        
        // Recalculate properly:
        // We need to cover [ymn[0], ymx[0]] starting from Ay
        if(Ay <= ymn[0]){
            // Go up to ymx, then can end at ymx or go down to ymn
            dp[0][1] = hdist + (ymx[0] - Ay);
            dp[0][0] = hdist + (ymx[0] - Ay) + range;
        } else if(Ay >= ymx[0]){
            // Go down to ymn, then can end at ymn or go up to ymx
            dp[0][0] = hdist + (Ay - ymn[0]);
            dp[0][1] = hdist + (Ay - ymn[0]) + range;
        } else {
            // Ay is between ymn and ymx
            // End at ymax: go down to ymn first, then up to ymx
            dp[0][1] = hdist + (Ay - ymn[0]) + range;
            // End at ymin: go up to ymx first, then down to ymn
            dp[0][0] = hdist + (ymx[0] - Ay) + range;
        }

        
        
        for(int i=1; i<m; i++){
            ll dx = xs[i] - xs[i-1];
            ll rng = ymx[i] - ymn[i];
            
            // From previous ymax[i-1]
            // From previous ymin[i-1]
            
            // End at ymax[i]: must visit ymn[i] first then go to ymx[i]
            ll fromPrevMax_toMax = dp[i-1][1] + dx + abs(ymn[i] - ymx[i-1]) + rng;
            ll fromPrevMin_toMax = dp[i-1][0] + dx + abs(ymn[i] - ymn[i-1]) + rng;
            dp[i][1] = min(fromPrevMax_toMax, fromPrevMin_toMax);
            
            // End at ymin[i]: must visit ymx[i] first then go to ymn[i]
            ll fromPrevMax_toMin = dp[i-1][1] + dx + abs(ymx[i] - ymx[i-1]) + rng;
            ll fromPrevMin_toMin = dp[i-1][0] + dx + abs(ymx[i] - ymn[i-1]) + rng;
            dp[i][0] = min(fromPrevMax_toMin, fromPrevMin_toMin);
        }
        
        // Final: go from last column to (Bx, By)
        ll ans1 = dp[m-1][1] + dist(xs[m-1], ymx[m-1], Bx, By);
        ll ans2 = dp[m-1][0] + dist(xs[m-1], ymn[m-1], Bx, By);
        
        cout << min(ans1, ans2) << '\n';
    }
    return 0;
}
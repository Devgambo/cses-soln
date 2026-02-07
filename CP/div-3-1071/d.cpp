#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
#define pb push_back
#define ff first
#define ss second

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n;
    cin>>n;
    int tot=(1LL<<n);
    vector<int>vis(tot);
    vi ans;
    for(int i=n;i>=0;i--){
        ans.pb((1LL<<i)-1);
        vis[ans.back()]=1;
        int ini=ans.back();
        int z=n-i; //number of zeros left
        int rem=n-(z-1);
        for(int j=1;j<(1<<(z-1));j++){
            int curr=(ini|(j<<rem));        // we're constructing the number to add the next (with the same number of bits after & op)
            ans.pb(curr);
            vis[ans.back()]=1;
        }
    }

    for(int i=0;i<tot;i++){
        if(!vis[i]){
            ans.pb(i);
        }
    }

    for(auto &x:ans)cout<<x<<" ";
    cout<<endl;
    return;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }
    return 0;
}
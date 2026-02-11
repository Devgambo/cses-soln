#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
#define pb push_back
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fast_io();
    int t=1;
    cin >> t;
    while(t--){
        ll p,q; 
        cin >> p >> q;
        bool ans = true;    //alice
        if(p==q){
            cout << "Alice" << '\n';
            continue;
        }
        ll x = (3 * p)- (2 * q);

        if(x >= 0){
            ans = false;
        }

        if(ans){
            cout << "Alice" << '\n';
        }else{
            cout << "Bob" << '\n';
        }
    }
    return 0;
}
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

int floor_root(int n){
    return (int)sqrt(n);
}

int main() {
    fast_io();
    int n;
    cin >> n;
    
    map<int, int> count;
    int limit = floor_root(n);
    
    for(int y = 1; y <= limit; y++){
        for(int x = 1; x < y; x++){
            int val = x*x + y*y;
            if(val <= n){
                count[val]++;
            } else {
                break;
            }
        }
    }
    
    vi ans;
    for(auto& p : count){
        if(p.second == 1){
            ans.push_back(p.first);
        }
    }
    
    cout << ans.size() << endl;
    for(int i : ans){
        cout << i << " ";
    }

    return 0;
}
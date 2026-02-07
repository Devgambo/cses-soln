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

int fun(int n){
    string s = to_string(n);
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        ans += (s[i]-'0')*(s[i]-'0');
    }

    return ans;
}

int main() {
    fast_io();

    int n;
    cin >> n;
    set<int> vis;
    
    while(n != 1 && vis.find(n) == vis.end()){
        vis.insert(n);
        n = fun(n);
    }

    if(n == 1){
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
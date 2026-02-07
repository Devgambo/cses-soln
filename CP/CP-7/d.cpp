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


void f(int n, vector<int> b, unordered_map<int,int> mp){
    vector<int> ans;
    unordered_map<int,int> pm;
    for(auto it:mp){
        pm[it.second] = it.first;
    }
    for(int i:b){
        if(pm.find(i)==mp.end()){
            cout<<-1;
            return;
        }
        ans.push_back((i+2)%n);
    }

    for(int i:ans){
        cout << i << " ";
    }
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            cin >> b[i];
            mp[b[i]]++;
        }
        f(n,b,mp);
        cout<<endl;
    }

    return 0;
}
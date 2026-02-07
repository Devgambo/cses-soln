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

void f(string org, string nw, int n, int m, string dv){
    for(int i=0 ; i<m; i++){
        if(dv[i]=='V'){
            org = nw[i] + org; 
        }else{
            org = org + nw[i];
        }
    }

    cout<<org;
    return;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        int m;
        string org;
        string nw, dv;
        cin >> n;
        cin >> org;
        cin >> m;
        cin >> nw;
        cin >> dv;
        f(org,nw,n,m,dv);
        cout<<endl;
    }

    return 0;
}
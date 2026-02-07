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

int main() {
    fast_io();
    int n, m , d;
    cin >> n >> m >> d;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }

    unordered_map<int,int> dist;
    for(int i=0; i<d; i++){
        int a ; 
        cin >> a;
        dist[a]++;
    }

    int maxAns = 0;
     for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<m; j++){
            if(dist.find(v[i][j]) != dist.end()){
                cnt++;
            }           
        }

        maxAns = max(maxAns , cnt);
    }

    cout << maxAns;

    return 0;
}
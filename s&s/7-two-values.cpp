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
    int n;
    ll x;
    cin >> n >> x;
    vector<pair<ll,int>> a(n);
    for(int i=0; i<n; i++){
        ll e;
        cin >> e;
        a[i] = {e, i + 1};
    }

    

    int i=0, j=n-1;
    while(i<j){
        if(a[i].first + a[j].first < x){
            i++;
        }
        else if(a[i].first + a[j].first > x){
            j--;
        }
        else{
            cout << a[i].second << " " << a[j].second ;
            return 0; 
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
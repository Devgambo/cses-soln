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
vi A;
int n;

int f(int i){
    return (i+A[i]-1);
}

int main() {
    fast_io();
    cin >> n;
    int ans = 0;
    A.resize(n);
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    if(A[0]==1){
        cout << 1;
        return 0;
    }
    int lastD = f(0);
    for(int i=1; i<n; i++){
        lastD = max(lastD, f(i));
        if(lastD <= i || i==n-1 ){
            ans = i;
            break;
        }
    }

    cout << ans+1;
    return 0;
}
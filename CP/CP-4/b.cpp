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

void f(int n){
    vi a(n);
    int od = (n%2==0)?n/2:(n/2)+1;
    int ev = n-od;
    int val = od+1;
    int ap = 0;
    for(int i=0; i<n; i++){
        if(i%2==0){
            a[i]=-1;
        }else{
            if(i>=n-2){
                a[i] = val-ap;
            }else{
                a[i] = 1;
                ap++;
            }
        }
    }
    for(int i:a){
        cout<<i<<" ";
    }

}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        f(n);
        cout<<endl;
    }

    return 0;
}
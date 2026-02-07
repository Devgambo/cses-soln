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

void f(int n, int a, int b){
    if(n%2==0){
        if(b%2!=0){
            cout<<"NO";
            return;
        }
        if(a>b && a%2!=0){
            cout<<"NO";
            return;
        }
    }else{
        if(b%2==0){
            cout<<"NO";
            return;
        }
        if(a>b && a%2==0){
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
    return;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >>n >>a >>b;
        f(n,a,b);
        cout<<endl;
    }

    return 0;
}
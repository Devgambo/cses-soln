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

bool valid(ull x , ull y){
    string n = to_string(x) + to_string(y);
    ull xy = stoull(n);
    return xy%(x+y) == 0;
}

void f(ull x){
    for(ull i=1; i<1e9; i++){
        if(valid(x,i)){
            cout<<i;
            return;
        }
    }
    return;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        ull n;
        cin >> n;
        f(n);
        cout<<endl;
    }

    return 0;
}
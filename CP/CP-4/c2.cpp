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


void f(int n,int k, multiset<int> S, multiset<int> T){
    if(S==T){
        cout<<"YES";
    }
    else 
        cout<<"NO";

}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        multiset<int> S;
        multiset<int> T;

        int x;
        for(int i = 0; i < n; i++) {
            cin >> x;
            if(x<k){
                S.insert(k-x);
            }else{
                S.insert(x%k);
            }
        }
        for(int i = 0; i < n; i++) {
            cin >> x;
            T.insert(x%k);
        }

        f(n, k, S, T);
        cout << endl;
    }

    return 0;
}

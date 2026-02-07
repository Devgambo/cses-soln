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

bool mingcd3(int i, int j) {
    // Euclidean algorithm to find gcd
    while (j != 0) {
        int temp = j;
        j = i % j;
        i = temp;
    }
    int gcd = i;
    return gcd >= 3;
}

void f(int n, vector<int> p, int i1, int i2){
    vector<int> q(n);
    unordered_map<int,int> mp;

    for(int i=1; i<=n; i++){
        mp[i]++;
    }

    int i=0,j=1;
    while(j<n){
    
        int pi1 = p[i];
        int pi2 = p[j];

        for(int k=0; k<n-1; k++){
            
        }


        i=j;
        j++;
    }

    for(int i:q){
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
        vector<int> p(n);
        for(int i=0; i<n; i++){
            cin >> p[i];
        }
        f(n,p);
        cout<<endl;
    }

    return 0;
}
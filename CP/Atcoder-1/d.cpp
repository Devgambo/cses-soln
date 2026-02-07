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

bool f(string a, string b, int m){
    int i=0;
    int na = a.size();
    while(a[i] == '0'){
        i++;
    }
    a = a.substr(i,na-i+1);
    i=0;
    int nb = b.size();
    while(b[i] == '0'){
        i++;
    }
    b = b.substr(i,nb-i+1);
    string c = a.append(b);
    if(stoull(c)%m==0)
        return true;
    return false;
}


int main() {
    fast_io();
    int n,m;
    cin >> n >>m;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            string a = to_string(A[i]);
            string b = to_string(A[j]);
            if(f(a,b,m))    ans++;
        }
    }


    cout << ans;


    return 0;
}
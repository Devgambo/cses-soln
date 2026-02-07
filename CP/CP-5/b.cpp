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
string subt(string a, string b){
    int n = stoi(a);
    int m = stoi(b);
    if(n-m < 0){
        return "Na";
    }
    string an = to_string(n-m);
    return an;
}
void f(int n){
    vi ans;
    string org = to_string(n);
    int sz = org.size();
    int q = sz/2;
    while(q>0){
        string cur;
        string sel = org.substr(sz-q,q);
        for()
        

    }
    return;
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
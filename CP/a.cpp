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
int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;  // safer than (a * b) / gcd to avoid overflow
}

void f(int a , int b){
    if(a==b){
        cout<<0;
        return;
    }
    int ans=0;
    int l = lcm(a,b);
    if(a!=l){
        ans++;
    }
    if(b!=l){
        ans++;
    }
    cout<<ans;
    return;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int k,x;
        cin >> k>> x;
        f(k,x);
        cout<<endl;
    }

    return 0;
}
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
    ll n;
    cin >> n;
    if(n==1){
        cout << 1;
        return 0;
    }
    if(n<=3){
        cout <<"NO SOLUTION";
        return 0;
    }
    
    deque<int> ans;
    ans.push_back(2);
    ans.push_back(4);
    ans.push_back(1);
    ans.push_back(3);

    int i = 5;
    while(i<=n){
        if(i%2==0)  ans.push_back(i);
        else ans.push_front(i);
        i++;
    }
    for(int i:ans){
        cout <<i <<" ";
    }
    return 0;
}
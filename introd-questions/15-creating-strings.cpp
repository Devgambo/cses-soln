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

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int fact(int n){
    if(n==1){
        return 1;
    }

    return n * fact(n-1);
}

        
int main()
{
    fast_io();
    string s;
    cin >> s;
    unordered_map<char,int> mp;
    int n = s.size();
    for(char c:s){
        mp[c]++;
    }
    sort(s.begin(), s.end());
    int ans = fact(n);
    for(auto [c,i]:mp){
        ans = ans / fact(i);
    }

    cout << ans<<endl;
    while(ans>0){
        ans--;
        cout <<s<<'\n';
        next_permutation(s.begin(), s.end());
    }
    return 0;
}
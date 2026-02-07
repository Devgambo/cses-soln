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

void f(vi a, vi b, int n){
    int o = 0;
    int e = 0;
    int o1 = 0;
    int e1 = 0;
    int flag = 1;
    for(int i=n-1; i>=0; i--){
        if(a[i]!=b[i] && flag==1){
            if(i%2==0)  o=1;
            else    e=1;
            flag = 0;
        }
        if(a[i]==1) o1++;
        if(b[i]==1) e1++;
    }

    if((o1%2!=0 && e1%2!=0) || (o1%2==0 && e1%2==0)){
        cout<<"Tie";
    }
    else if(o==1){
        cout << "Ajisai";
    }else if(e==1){
        cout <<"Mai";
    }else{
        cout << "Tie";
    }
    return;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while(t>0){
        t--;
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        f(a,b,n);
        cout<<endl;
    }
    return 0;
}
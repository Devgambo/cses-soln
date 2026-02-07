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

void f(vi a, vi b, int n)
{
    for (int bit = 30; bit >= 0; bit--)
    {
        int cnta=0, cntb=0;
        for (int i = 1; i <= n; i++){
            if (a[i] & (1ll << bit)){
                cnta++;
            }
            if (b[i] & (1ll << bit)){
                cntb++;
            }
        }   
        if(cnta%2 == cntb%2)    continue;
        for(int i=n; i>=1; i--){
            if((a[i]&(1ll<<bit)) != (b[i]&(1ll<<bit))) {
                if(i%2==1){
                    cout<<"Ajisai"<<endl;
                }else{
                    cout<<"Mai"<<endl;
                }
                return;
            }
        }
    }
    cout<<"Tie"<<endl;
    return;
}

int main()
{
    fast_io();
    int t;
    cin >> t;
    while (t > 0)
    {
        t--;
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        vector<int> b(n+1,0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        f(a, b, n);
        cout << endl;
    }
    return 0;
}
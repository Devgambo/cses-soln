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

void f(vector<int> v, int n)
{

    if (n == 1)
    {
        if (v[0] == -1)
        {
            cout << 0 << endl;
            cout << 0 << endl;
        }
        else
        {
            cout << v[0] << endl;
            cout << v[0] << endl;
        }
        return;
    }

    int cs = 0;
    if (v[0] == -1 && v[n - 1] == -1){
        cout<<0<<endl;
        for(int i:v){
            if(i!=-1)   cout<<i<<" ";
            else cout<<0<<" ";
        }
    }else if(v[0]!=-1 && v[n-1]==-1){
        cout << 0<< endl;
        v[n-1] = v[0];
        for(int i:v){
            if(i!=-1)   cout<<i<<" ";
            else cout<<0<<" ";
        }
    }else if(v[0]==-1 && v[n-1]!=-1){
        cout << 0<< endl;
        v[0] = v[n-1];
        for(int i:v){
            if(i!=-1)   cout<<i<<" ";
            else cout<<0<<" ";
        }
    }else{
        cout << abs(v[n-1]-v[0])<< endl;
        for(int i:v){
            if(i!=-1)   cout<<i<<" ";
            else cout<<0<<" ";
        }
    }
    cout<<endl;
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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        f(v, n);
    }
    return 0;
}
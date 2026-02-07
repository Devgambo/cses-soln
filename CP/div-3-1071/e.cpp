#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
// #define double long double
#define int long long
#define vi vector<int>
#define all(a) a.begin(),a.end()

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    vector<int>p(n);
    for(auto &x:p)cin>>x;

    int sum=accumulate(all(p),0LL);

    if(sum>x+y){
        cout<<"NO\n";
        return;
    }

    vector<int>tar(n);
    for(int i=0;i<n;i++){
        tar[i]=p[i]/2+1;//atleast this much
    }
    int rx=0,ry=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            rx+=tar[i];
        }
        else{
            ry+=tar[i];
        }
    }

    if(rx<=x&&ry<=y){
        bool all_one=1,all_zero=1;
        for(auto &x:s){
            if(x=='1')all_zero=0;
            else all_one=0;
        }
        if(all_zero){
            if(x>=y+n){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else if(all_one){
            if(y>=x+n){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

int32_t main(){
    #ifdef MYPC2835
       freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    //    freopen("error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
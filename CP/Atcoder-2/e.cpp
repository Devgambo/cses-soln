#include <bits/stdc++.h>
#define loop(i, l, r) for(int i = (l); i < (r); ++i)
#define pool(i, l, r) for(int i = (l); i > (r); --i)
#define debug(x) cerr << #x << ": " << x << endl;
using namespace std;
int n;
vector<long long> X; 
vector<long long> R; 
long long ans = 0;
void fun(unordered_map<long long,int> &mp, int i, int n, bool flag, vector<pair<int,int>> pos){
    if(i==n-1){
        ans = max(ans, (long long)mp.size());
        return;
    }
    if(flag){
        mp[pos[i].first]++;
    }else{
        mp[pos[i].second]++;
    }
    fun(mp,i+1,n,!flag,pos);
    fun(mp,i+1,n,flag,pos);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0; i<n; i++){
        int x,r;
        cin>>x>>r;
        X.push_back(x);
        R.push_back(r);
    }

    vector<pair<int,int>> pos(n);
    for(int i=0; i<n; i++){
        pos[i]={X[i]-R[i], X[i]+R[i]};
    }

    unordered_map<long long,int> mp;
    fun(mp, 0, n, true, pos);
    fun(mp, 0, n, false, pos);
    cout << ans;
    return 0;
}

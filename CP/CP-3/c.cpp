#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

void f(int n, int k, vector<int> h){
    if(h[k-1]<1){
        cout<<"NO";
        return;
    }
    vector<pair<int,int>> s;
    for(int i=0;i<n;i++){
        if(i!=k-1){
            s.push_back({h[i],0});
        }else{
            s.push_back({h[i],1});
        }
    }
    
    sort(s.begin(),s.end(), [](const pair<int,int>&a,const pair<int,int>&b){
        return a.ff<b.ff;
    });

    for(int i=0;i<n; i++){
        if(s[i].ss == 1){
            k = i; 
        }
    }
    int w=0;
    while(k<n-1){
        int left = s[k].ff - w;
        int next = s[k+1].ff - s[k].ff;
        if(next>left){
            cout<<"NO";
            return;
        }
        w += left;
        k = k+1;
    }

    cout<<"YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        f(n,k,a);
        cout<<endl;
    }

    return 0;
}

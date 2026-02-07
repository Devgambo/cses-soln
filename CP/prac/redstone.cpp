#include <bits/stdc++.h>
using namespace std;


void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void f(vector<int> vec){
    int n = vec.size();
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        if(mp.count(vec[i])>0){
            cout<<"YES";
            return;
        }
        mp[vec[i]]++;
    }
    cout<<"NO";
    return;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for(int i=0 ; i<n; i++){
            cin >> vec[i];
        }
        f(vec);
        cout<<endl;
    }
    return 0;
}
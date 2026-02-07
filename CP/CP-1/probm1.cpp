#include <bits/stdc++.h>
using namespace std;

string func(){
    int n;
    cin>>n; 
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    string ans="";
    int mini = *min_element(a.begin(),a.end());
    int maxi = *max_element(a.begin(),a.end());
    for(int i=0; i<n; i++){
        if(i==0 || i==n-1){
            ans +="1";
        }
        else if(a[i]==mini || a[i]==maxi){
            ans += "1";
        }else{
            ans += "0";
        }
    }

    return ans;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        cout << func()<< endl;
    }
    return 0;
}
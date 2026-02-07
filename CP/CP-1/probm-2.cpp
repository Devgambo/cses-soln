#include <bits/stdc++.h>
using namespace std;

string func(){
    int n,k;
    string s;
    cin>>n>>k; 
    cin >> s;

    int no = 0;
    int nl = 0;
    for(char x:s){
        if(x=='0')  no++;
        else nl++;
    }
    if(nl<=k)    return "Alice";
    if(k > (n/2))   return "Alice";
    return "Bob";
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        cout << func()<< endl;
    }
    return 0;
}
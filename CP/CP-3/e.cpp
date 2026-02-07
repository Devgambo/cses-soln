#include <bits/stdc++.h>
using namespace std;


int gcf(int a, int b) {
    if (a == b) return a;
    if (a > b) return gcf(a - b, b);
    else return gcf(a, b - a);
}

bool f(int n, vector<int> p, vector<int> s){
    int g = p[n-1];
    if(g!=s[0])   return false;
    int i=0;
    while( i<n ){
        int ng = gcf(p[i],s[i]);
        if(g!=ng) return false;
        i++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        vector<int> s(n);
        for(int i=0; i<n; i++){
            cin >> p[i];
        }
        for(int i=0; i<n; i++){
            cin >> s[i];
        }
        if(f(n,p,s)){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<endl;
    }

    return 0;
}

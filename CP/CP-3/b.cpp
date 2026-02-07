#include <bits/stdc++.h>
using namespace std;

void f(int n, int k, vector<int> a){
    int ans=0;
    int c=0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            c+=1;
        }
        else{
            c=0;
        }

        if (c== k) {
            c = 0;
            i++;
            ans++;
        }
    }

    cout<<ans;
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

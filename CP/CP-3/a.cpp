#include <bits/stdc++.h>
using namespace std;



void f(int x){
    int ans = INT_MAX;
    int temp=0;
    while(x>0){
        temp = x%10;
        x = x/10;
        ans = min(ans,temp);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        f(x);
        cout<<endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void f(string &c, int ind, int k, char last_char, long &ans){
    if(k == 3){
        ans++;
        return;
    }
    if(ind >= c.size()) return;

    f(c, ind + 1, k, last_char, ans);

    if(last_char == 'x' || c[ind] != last_char){
        f(c, ind + 1, k + 1, c[ind], ans);
    }
}

long countw(string c){
    long ans = 0;
    f(c, 0, 0, 'x', ans);
    return ans;
}

int main() {
    string s = "10111";
    cout << countw(s) << endl;
    return 0;
}

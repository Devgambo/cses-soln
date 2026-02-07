#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "hello hhdir";
    char b = 'h';
    int a = count_if(s.begin(),s.end(), [&](char x){
        return x==b;
    });
    cout<<a;
    return 0;
}

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string process(string s) {
    string ans = "";
    int n = s.length();
    int i = 0;
    int cnt = 0;

    while (i < n) {
        if (s[i] == ' ') {
            ans += ' ';
            i++;
        }
        else if (cnt > 0) {
            // Skip this character if it's alphabet
            if (isalpha(s[i])) {
                cnt--;
            }
            i++;
        }
        else if (isalpha(s[i])) {
            ans += s[i++];
        }
        else {
            // It's a special character: mark to skip next alpha
            cnt++;
            i++; // skip special char
        }
    }

    return ans;
}

int main(){
    string s;
    getline(cin,s);
    cout<<process(s);
    return 0;
}
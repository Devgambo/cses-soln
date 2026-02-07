#include <bits/stdc++.h>
using namespace std;

bool allEqualFreq(const unordered_map<char,int>& freq) {
    if (freq.empty()) return false;
    int val = freq.begin()->second;
    for (auto &p : freq) {
        if (p.second != val) return false;
    }
    return true;
}

int minSubstrings(string s) {
    unordered_map<char,int> freq;
    int count = 0;

    for (char c : s) {
        freq[c]++;
        if (allEqualFreq(freq)) {
            count++;
            freq.clear();
        }
    }

    return count;
}

int main() {
    string s;
    cin >> s;
    cout << minSubstrings(s) << "\n";
    return 0;
}

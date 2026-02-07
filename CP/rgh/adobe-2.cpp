#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
void process_group(const vector<int>& group, vector<vector<int>>& trios, int& total_cost) {
    for (int i = 0; i + 2 < group.size(); i += 3) {
        vector<int> trio = {group[i], group[i+1], group[i+2]};
        trios.push_back(trio);
        int sum = trio[0] + trio[1] + trio[2];
        int max_val = max({trio[0], trio[1], trio[2]});
        total_cost += sum - max_val / 2;
    }
}

void solve(int n, const vector<int>& prices) {
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) even.push_back(prices[i]);
        else odd.push_back(prices[i]);
    }

    vector<vector<int>> result;
    int total_cost = 0;

    process_group(even, result, total_cost);
    process_group(odd, result, total_cost);

    if (result.empty()) {
        cout << 0 << endl;
        return;
    }

    for (const auto& trio : result) {
        for (int val : trio) cout << val << " ";
        cout << endl;
    }

    cout << total_cost << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    solve(n, prices);
    return 0;
}

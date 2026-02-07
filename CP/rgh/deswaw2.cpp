#include <bits/stdc++.h>
using namespace std;


int minop(vector<int> v){
    int n =v.size();
    int i =1;
    int op = 0;
    while(i<n){
        if(v[i-1]>=v[i]){
            i++;
            continue;
        }
        else if(v[i-1]<v[i]){
            // while(i+1<n && v[i]>=v[i+1]){
            //     v[i+1]++;
            //     v[i]--;
            //     op++;
            //     if(v[i-1]==v[i]){
            //         i++;
            //         break;
            //     }
            // }
            v[i-1]++;
            v[i]--;
            op++;
            i = i-1;
        }
        
    }
    return op;
}

int main() {
    vector<int> v ={6,4,3,5,3,1};
    cout << minop(v) << endl;
    return 0;
}

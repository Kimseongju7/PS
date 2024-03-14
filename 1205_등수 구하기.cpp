#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int p, n, s;
    cin >> n >> s >> p;
    vector<int> v(n + 1);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    if(v[p - 1] >= s && n != 0 && p == n) cout << -1 << endl;
    else {
        v.push_back(s);
        sort(v.rbegin(), v.rend());
        for(int i = 0; i < p; ++i){
            if(s == v[i]) {
                cout << i + 1 << endl; 
                break;
            }
        }
    }
}
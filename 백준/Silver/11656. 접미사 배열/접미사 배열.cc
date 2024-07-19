#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    vector<string> v;
    cin >> s;
    string ts = "";
    for(int i = s.size() - 1; i >= 0; --i){
        ts =  s[i] + ts;
        v.emplace_back(ts);
    }
    sort(v.begin(), v.end());
    for(auto i : v) cout << i << endl;
    return 0;
}
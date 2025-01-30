#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<string> v[10101];
    string s, name; int N, dap = 10101, U, n, cnt[10101] = {};
    cin >> U >> N;
    for(int i = 1; i <= N; ++i){
        cin >> s >> n;
        cnt[n]++;
        v[n].emplace_back(s);
    }
    n = 101010;
    dap = 10101;
    for(int i = 1; i <= U; ++i){
        if(cnt[i] == 0) continue;
        if(cnt[i] < n){
            n = cnt[i];
            dap = i;
        }
    }
    name = v[dap][0];
    cout << name << ' ' << dap;
    return 0;
}
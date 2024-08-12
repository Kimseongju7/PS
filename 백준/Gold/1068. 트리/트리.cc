#include<iostream>
#include<vector>
using namespace std;

vector<int> G[55];
int P[55], N, C[55], dap;

void dfs(int v){
    int cnt = 0;
    //C[v] = 1;
    for(auto i : G[v]) ++cnt, dfs(i);
    if(!cnt) ++dap;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; ++i){
        int t; cin >> t;
        P[i] = t;
    }
    int t, r = -1; cin >> t;
    P[t] = -2;
    for(int i = 0; i < N; ++i){
        if(P[i] == -1) r = i;
        else if(P[i] == -2) continue;
        else G[P[i]].emplace_back(i);
    }
    if(r != -1) dfs(r);
    cout << dap;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int C[1010], dap, N, M;
vector<int> G[1010];

void dfs(int s){
    C[s] = 1;
    for(auto i : G[s]) if(!C[i]) dfs(i);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i< M; ++i){
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for(int i = 1; i <= N; ++i){
        if(!C[i]){
            ++dap;
            dfs(i);
        }
    }
    cout << dap;
    return 0;
}
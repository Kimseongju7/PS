#include<iostream>
#include<vector>
using namespace std;

int C[202], A[202], n = 1;
vector<int> G[202];
int dfs(int v){
    for(auto i : G[v]){
        if(C[i] == n) continue;
        C[i] = n;
        if(A[i] == 0 || dfs(A[i])){
            A[i] = v;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, K, u, v, dap = 0; cin >> N >> M >> K;
    for(int i = 1; i <= K; ++i){
        cin >> u >> v;
        G[u].emplace_back(v);
    }
    for(int i = 1; i <= N; ++i){
        dap += dfs(i);
        ++n;
    }
    cout << N + M -dap;
    return 0;
}
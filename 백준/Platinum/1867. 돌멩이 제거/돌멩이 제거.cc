#include<iostream>
#include<vector>
using namespace std;

int C[505], A[505], visitNum = 1;
vector<int> G[505];

int dfs(int v){
    for(auto i : G[v]){
        if(C[i] == visitNum) continue;
        C[i] = visitNum;
        if(A[i] == 0 || dfs(A[i])){
            A[i] = v;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K, dap = 0;
    cin >> N >> K;
    for(int i = 1, u, v; i <= K; ++i){
        cin >> u >> v;
        G[u].emplace_back(v);
    }
    for(int i = 1; i <= N; ++i){
        dap += dfs(i);
        ++visitNum;
    }
    cout << dap;
    return 0;
}
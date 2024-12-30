#include<iostream>
#include<vector>
using namespace std;
vector<int> G[101];
int C[101], A[101], N, M, visitNum = 1, dap;

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
    cin >> N >> M;
    int u, v;
    for(int i = 1; i <= M; ++i){
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
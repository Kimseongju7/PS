#include<iostream>
#include<vector>
using namespace std;

int A[202], C[202], n = 1;
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
    int N, M, dap = 0, u, v; cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        cin >> u >> v;
        if(u & 1) {
            if(!(v & 1)) G[u].emplace_back(v);
        }
        else{
            if(v & 1) G[v].emplace_back(u);
        } 
    }
    for(int i = 1; i <= N; i += 2){
        dap += dfs(i);
        ++n;
    }
    dap *= 2;
    if(dap < N && !(dap & 1)) ++dap;
    cout << dap;
    return 0;
}
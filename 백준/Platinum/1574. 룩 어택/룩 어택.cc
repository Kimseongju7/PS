#include<iostream>
#include<vector>
using namespace std;

int A[303], C[303], num = 1, Chess[303][303];
vector<int> G[303];

int dfs(int v){
    for(auto i : G[v]){
        if(C[i] == num) continue;
        C[i] = num;
        if(A[i] == 0 || dfs(A[i])){
            A[i] = v;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int R, C, N, dap = 0;
    cin >> R >> C >> N;
    int u, v; 
    for(int i = 1; i <= N; ++i){
        cin >> u >> v;
        Chess[u][v] = 1;
    }
    for(int i = 1; i <= R;++i){
        for(int j = 1; j <= C; ++j){
            if(!Chess[i][j]) G[i].emplace_back(j);
        }
    }
    for(int i = 1; i <= R; ++i){
        dap += dfs(i);
        ++num;
    }
    cout << dap;
    return 0;
}
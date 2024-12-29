#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int C[1010], dap, A[1010];
vector<int> G[1010];

int dfs(int v){
    for(auto i : G[v]){
        if(C[i]) continue;
        C[i] = 1;
        if(A[i] == 0 || dfs(A[i])){
            A[i] = v;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, n;
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        int u; cin >> n;
        for(int j = 1; j <= n; ++j){
            cin >> u;
            G[i].emplace_back(u);
        }
    }
    for(int i = 1; i <= N; ++i) {
        memset(C, 0, sizeof(C));
        dap += dfs(i);
    }
    cout << dap;
    return 0;
}
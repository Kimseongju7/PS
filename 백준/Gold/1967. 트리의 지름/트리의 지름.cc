#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;

vector<pair<int, int> > G[10101];
int C[10101] = {}, dap;
int D[10101];

void dfs(int v, int t){
    if(C[v]) return;
    C[v] = 1;
    D[v] = t;
    for(auto [i, w] : G[v]){
        dfs(i, t + w);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int dap = 0, N, u, v, w;
    cin >> N;
    for(int i = 1; i < N; ++i) {
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    dfs(1, 0);
    for(int i = 1; i <= N; ++i) {
        if(dap <= D[i]){
            dap = D[i];
            v = i;
        }
    }
    memset(C, 0, sizeof(C));
    dfs(v, 0);
    for(int i = 1; i <= N; ++i) dap = max(dap, D[i]);
    cout << dap;
    return 0;
}
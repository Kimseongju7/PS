#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dap, N, M;
vector<int> G[111];
int C[111];

void bfs(int s){
    queue<int> q;
    q.emplace(s); C[s] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : G[u]){
            if(C[v]) continue;
            C[v] = 1;
            ++dap;
            q.emplace(v);
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    bfs(1);
    cout << dap;
    return 0;
}
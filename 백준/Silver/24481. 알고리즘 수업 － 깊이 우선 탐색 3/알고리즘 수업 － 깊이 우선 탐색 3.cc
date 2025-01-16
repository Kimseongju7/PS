#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> G[101010];
int D[101010];

void dfs(int v, int n){
    if(D[v] != -1) return;
    D[v] = n;
    for(auto i : G[v]) dfs(i, n + 1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, R; cin >> N >> M >> R;
    int u, v; 
    for(int i = 1; i <= M; ++i){
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for(int i = 1; i <= N; ++i) { D[i] = -1; sort(G[i].begin(), G[i].end()); }
    dfs(R, 0);
    for(int i = 1; i <= N; ++i) cout << D[i] << '\n';
    return 0;
}
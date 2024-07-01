#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;

int dap[101010], C[101010];
vector<int> G[101010];
int N, M, cnt;

void dfs(int s){
    C[s] = 1;
    dap[s] = ++cnt;
    for(auto i : G[s]) if(!C[i]) dfs(i);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int s;
    cin >> N >> M >> s;
    for(int i = 0; i < M; ++i){
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for(int i = 1; i <= N; ++i) sort(G[i].begin(), G[i].end());
    dfs(s);
    for(int i = 1; i <= N; ++i) cout << dap[i] << endl;
    return 0;
}
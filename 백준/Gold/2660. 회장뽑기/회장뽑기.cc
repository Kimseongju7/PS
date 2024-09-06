#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;

int D[55][55], N;
int path[55];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i = 0; i <= N; ++i) D[i][i] = 0;
    while(true){
        int u, v; cin >> u >> v;
        if(u == -1) break;
        D[u][v] = min(D[u][v], 1);
        D[v][u] = min(D[v][u], 1);
    }
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    int minPath = INF;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j) path[i] = max(path[i], D[i][j]);
        minPath = min(minPath, path[i]);
    }
    vector<int> dap;
    for(int i = 1; i <= N; ++i) if(minPath == path[i]) dap.emplace_back(i);
    cout << minPath << ' ' << dap.size() << '\n';
    for(auto i : dap) cout << i << ' ';
    return 0;
}
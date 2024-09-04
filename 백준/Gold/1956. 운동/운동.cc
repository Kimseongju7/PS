#include<iostream>
using namespace std;
#define INF 1e9
int D[404][404], N, E;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> E;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i = 1; i <= E; ++i){
        int s, e, w; cin >> s >> e >> w;
        D[s][e] = w;
    }
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    int dap = INF;
    for(int i = 1;i <= N; ++i) for(int j = i + 1; j <= N; ++j){
        dap = min(D[i][j] + D[j][i], dap);
    }
    if(dap == INF) cout << -1;
    else cout << dap;
}
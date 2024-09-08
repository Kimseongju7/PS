#include<iostream>
#define INF 1e9
#define endl '\n'
using namespace std;

int D[202][202], N, M, dap[202][202];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF, dap[i][j] = j;
    for(int i = 1; i <= N; ++i) D[i][i] = 0;
    for(int i = 0; i < M; ++i){
        int u, v, w; cin >> u >> v >> w;
        if(D[u][v] > w){
            dap[u][v] = v; 
            D[u][v] = w;
        }
        if(D[v][u] > w){
            dap[v][u] = u; D[v][u] = w;
        }
    }
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    dap[i][j] = dap[i][k];
                }
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(i == j) cout << '-' << ' ';
            else cout << dap[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
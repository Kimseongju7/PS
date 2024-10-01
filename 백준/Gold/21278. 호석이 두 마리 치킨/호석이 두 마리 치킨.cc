#include<iostream>
using namespace std;
#define INF 1e9

int D[101][101], N, M;
int dap1, dap2, dapSum = INF;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1 ;i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = 1;
    for(int i = 1; i <= N; ++i) D[i][i] = 0;
    for(int i = 1;i <= M; ++i){
        int u, v; cin >> u >> v;
        D[u][v] = 1; D[v][u] = 1;
    }
    for(int k = 1; k <= N; ++k) for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j){
        int sum = 0;
        for(int k = 1; k <= N; ++k){
            sum += min(D[i][k], D[j][k]);
        }
        if(sum < dapSum){
            dapSum = sum;
            dap1 = i;
            dap2 = j;
        }
    }
    cout << dap1 << ' ' << dap2 << ' ' << dapSum * 2;
    return 0;
}
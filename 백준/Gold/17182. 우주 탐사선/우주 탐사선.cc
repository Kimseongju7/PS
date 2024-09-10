#include<iostream>
using namespace std;
int N, K, D[20][20], C[11], P[22][22], dap = 1e9;

void dfs(int s, int n, int dist){
    if(dist > dap) return;
    if(n == N){
        dap = min(dap, dist);
        return;
    }
    for(int i = 1; i <= N; ++i){
        if(C[i]) continue;
        C[i] = 1;
        dfs(i, n + 1, dist + D[s][i]);
        C[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    ++K;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) cin >> D[i][j];
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                if(D[i][j] > D[i][k]+D[k][j]) P[i][j] = k;
            }
        }
    }
    C[K] = 1;
    dfs(K, 1, 0);
    cout << dap;
    return 0;
}

#include<iostream>
using namespace std;
#define INF 1e9
int D[505][505], N, M;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i = 1; i <= N; ++i) D[i][i] = 0;
    for(int i = 1; i <= M; ++i){
        int s, e, w; cin >> s >> e;
        D[s][e] = min(D[s][e], 1);
    }
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    int dap = N;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(D[i][j] == INF && D[j][i] == INF) {
                --dap;
                break;
            }
        }
    }
    cout << dap;
    return 0;
}

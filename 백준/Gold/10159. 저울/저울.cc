#include<iostream>
using namespace std;
#define INF 1e9
#define ednl '\n'
int D[111][111], N, M;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i = 1; i <= N; ++i) D[i][i] = 0;
    for(int i = 1; i <= M; ++i){
        int u, v;
        cin >> u >> v;
        D[u][v] = min(1, D[u][v]);
    }
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        int cnt = 0;
        for(int j = 1; j <= N; ++j){
            if(D[i][j] == INF && D[j][i] == INF) ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}
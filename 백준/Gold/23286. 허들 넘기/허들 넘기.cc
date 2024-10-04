#include<iostream>
using namespace std;
#define INF 1e7
int D[303][303], N, M, T;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> T;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i  =1 ;i <= N; ++i) D[i][i] = 0;
    for(int i = 1; i <= M; ++i){
        int s, e, h; cin >> s >> e >> h;
        D[s][e] = h;
    }
    for(int k = 1; k <= N; ++k) for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j){
        D[i][j] = min(D[i][j], max(D[i][k], D[k][j]));
    }
    for(int i = 1; i <= T; ++i){
        int s, e; cin >> s >> e;
        cout << ((D[s][e] == INF) ? -1 : D[s][e]) << '\n';
    }
    return 0;
}
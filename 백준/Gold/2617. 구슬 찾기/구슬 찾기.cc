#include<iostream>
#define INF 1e9
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, D[101][101] = {}, dap = 0, M;
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i = 1; i <= N; ++i) D[i][i] = 0;
    while(M--){
        int s, e; cin >> s >> e;
        D[s][e] = 1;
    }
    for(int k = 1; k <= N; ++k) for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    M = N / 2 + 1;
    for(int i = 1; i <= N; ++i){
        int cnt = 0;
        for(int j = 1; j <= N; ++j){
            if(i == j) continue;
            if(D[i][j] != INF) ++cnt;
        }
        if(cnt >= M){
            ++dap;
            continue;
        }
        cnt = 0;
        for(int j = 1; j <= N; ++j){
            if(i == j) continue;
            if(D[j][i] != INF) ++cnt;
        }
        if(cnt >= M) ++dap;
    }
    cout << dap;
    return 0;
}
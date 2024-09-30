#include<iostream>
using namespace std;
#define INF 1e9
int N, D[255][255], D1[255][255], M, K;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF, D1[i][j] = INF;
    for(int i = 1; i <= N; ++i) D[i][i] = 0, D1[i][i] = 0;
    for(int i = 1; i <= M; ++i){
        int u, v, b;
        cin >> u >> v >> b;
        if(b) D[v][u] = 0;
        else D[v][u] = 1;
        D[u][v] = 0;
        //D1[u][v] = 1;
        //D1[v][u] = 1;
    }
    for(int k = 1; k <= N; ++k) for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j){
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
        //D1[i][j] = min(D1[i][j], D1[i][k] + D1[k][j]);
    }
    cin >> K;
    for(int i = 1; i <= K; ++i){
        int s, e; cin >> s >> e;
        cout << D[s][e] << '\n';
        //cout << D[s][e] - D1[s][e] << '\n';
        //cout << D[s][e] << ' ' << D1[s][e] << '\n';
    }
    return 0;
}
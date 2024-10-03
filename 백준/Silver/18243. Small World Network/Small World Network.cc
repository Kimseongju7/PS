#include<iostream>
using namespace std;
#define INF 1000
int N, K, D[101][101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    //for(int i = 1; i <= N; ++i) D[i][i] = 0;
    for(int i = 1; i <= K; ++i){
        int u, v; cin >> u >> v;
        D[u][v] = 1;
        D[v][u] = 1;
    }
    for(int k = 1; k <= N; ++k) for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    for(int i = 1 ;i <= N; ++i) for(int j = 1; j <= N; ++j){
        if(D[i][j] > 6) {
            cout << "Big World!";
            return 0;
        }
    }
    cout << "Small World!\n";
    return 0;
}
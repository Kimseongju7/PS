#include<iostream>
#define INF 404
#define endl '\n'
using namespace std;

int D[404][404], N, M, S;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M; 
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i = 1; i <= N; ++i) D[i][i] = 0;
    for(int i = 1; i <= M; ++i) {
        int s, e; cin >> s >> e;
        D[s][e] = 1;
    }
    for(int k = 1; k <= N; ++k) for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    cin >> S;
    while(S--){
        int s, e; cin >> s >> e;
        if(D[s][e] != INF) cout << -1 << endl;
        else if(D[e][s] != INF) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
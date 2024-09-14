#include<iostream>
using namespace std;
int D[505][505], N, M;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) cin >> D[i][j];
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    while(M--){
        int s, e, c; cin >> s >> e >> c;
        if(D[s][e] <= c) cout << "Enjoy other party\n";
        else cout << "Stay here\n";
    }
    return 0;
}
#include<iostream>
using namespace std;
#define INF 1e9
int D[55][55], N, dap;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> N;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j){
        char c; cin >> c;
        if(c == 'Y') D[i][j] = min(D[i][j], 1);
    }
    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    // for(int i = 1; i <= N; ++i) {
    //     for(int j = 1; j <= N; ++j) if(D[i][j] != INF) cout << D[i][j] << ' '; else cout << "INF" << ' ';
    //     cout << '\n';
    // }
    for(int i = 1; i <= N; ++i){
        int cnt = 0;
        for(int j = 1; j <= N; ++j){
            if(i == j) continue;
            if(D[i][j] <= 2) ++cnt;
        }
        dap = max(cnt, dap);
    }
    cout << dap;
    return 0;
}
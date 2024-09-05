#include<iostream>
#define INF 1e9
using namespace std;
int N;
int D[111][111];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j){
            D[i][j] = INF;
        }
    }
    //for(int i = 1; i <= N; ++i) D[i][i] = 0;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j){
        int n; cin >> n;
        if(n) D[i][j] = 1;
    }
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) cout << (D[i][j] == INF ? 0 : 1) << ' ';
        cout << '\n';
    }
    return 0;
}
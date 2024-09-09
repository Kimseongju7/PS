#include<iostream>
using namespace std;

int D[22][22], N, dap[22][22], Dap;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) {
        cin >> D[i][j];
        dap[i][j] = D[i][j];
    }
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                if(i == k || j == k) continue;
                if(D[i][j] == D[i][k] + D[k][j]) dap[i][j] = 0;
                if(D[i][j] > D[i][k] + D[k][j]) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j) Dap += dap[i][j];
    }
    cout << Dap / 2;
    return 0;
}
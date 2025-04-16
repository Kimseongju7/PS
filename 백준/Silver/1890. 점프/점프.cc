#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int A[101][101] = {};
    long long dap[101][101] = {};
    int N;
    cin >> N;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) cin >> A[i][j];
    dap[1][1] = 1;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(A[i][j] == 0) continue;
            if(i + A[i][j] <= N){
                dap[i + A[i][j]][j] += dap[i][j];
            }
            if(j + A[i][j] <= N){
                dap[i][j + A[i][j]] += dap[i][j];
            }
        }
    }
    // for(int i = 1; i <= N; ++i){
    //     for(int j = 1; j <= N; ++j){
    //         cout << dap[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dap[N][N];
    return 0;
}
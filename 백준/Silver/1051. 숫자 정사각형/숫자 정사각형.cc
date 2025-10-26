#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, A[55][55] = {}, dap = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
        char c; cin >> c;
        A[i][j] = c - '0';
    }
    int K = min(N, M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < K; k++){
                if(i + k >= N || j + k >= M) continue;
                if(A[i][j] == A[i + k][j] && A[i + k][j] == A[i + k][j + k] && A[i + k][j + k] == A[i][j + k]){
                    dap = max(dap, (k + 1) * (k + 1));
                }
            }
        }
    }
    cout << dap;
    return 0;
}
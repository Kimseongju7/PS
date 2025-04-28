#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int R, C;
    int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, cnt = 0;
    char A[101][101];
    int D[101][101];
    while(1){
        cin >> R >> C;
        if(!R && !C) break;
        for(int i = 1; i <= R; ++i) for(int j = 1; j <= C; ++j) cin >> A[i][j];
        for(int i = 1; i <= R; ++i) for(int j = 1; j <= C; ++j){
            if(A[i][j] == '*') D[i][j] = '*';
            else {
                cnt = 0;
                for(int k = 0; k < 8; ++k){
                    int ii = i + di[k], jj = j + dj[k];
                    if(ii < 1 || ii > R || jj < 1 || jj > C) continue;
                    if(A[ii][jj] == '*') ++cnt;
                }
                D[i][j] = cnt;
            }
        }
        for(int i = 1;i <= R; ++i) {
            for(int j = 1; j <= C; ++j) {
                if(D[i][j] == '*') cout << '*';
                else cout << D[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
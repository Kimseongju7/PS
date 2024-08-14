#include<iostream>
using namespace std;
int dap, cnt, N;
int d[111][111], C[111][111];
int di[4] = {0, 0, -1, 1}, dj[4] = {1, -1, 0, 0}, stand, maxStand;

void init(){
    cnt = 0;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) C[i][j] = 0;
}

void dfs(int i, int j){
    C[i][j] = 1;
    for(int k = 0; k < 4; ++k){
        int r = i + di[k], c = j + dj[k];
        if(!C[r][c] && d[r][c] >= stand) dfs(r, c);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j){
        cin >> d[i][j];
        maxStand = max(maxStand, d[i][j]);
    }
    for(stand = 0; stand <= maxStand; ++stand){
        init();
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                if(!C[i][j] && d[i][j] >= stand) {
                    ++cnt;
                    dfs(i, j);
                }
            }
        }
        dap = max(dap, cnt);
    }
    cout << dap;
    return 0;
}
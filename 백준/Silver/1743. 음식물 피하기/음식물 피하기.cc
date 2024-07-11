#include<iostream>
using namespace std;

int C[111][111], G[111][111], N, M, K, dap;
int di[4] = {0, 0, -1, 1}, dj[4] = {1, -1, 0, 0}, t;

void dfs(int i, int j){
    C[i][j] = 1;
    ++t;
    for(int k = 0; k < 4; ++k){
        int r = i + di[k], c = j + dj[k];
        if(r < 1 && r > N && c < 1 && c > M) continue;
        if(!C[r][c] && G[r][c]) dfs(r, c);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> K;
    for(int i = 1; i <= K; ++i){
        int r, c;
        cin >> r >> c;
        G[r][c] = 1;
    }
    for(int i = 1; i <= 100; ++i){
        for(int j = 1; j <= 100; ++j){
            if(!C[i][j] && G[i][j]){
                t = 0;
                dfs(i, j);
                dap = max(dap, t);
            }
        }
    }
    cout << dap;
    return 0;   
}
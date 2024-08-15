#include<iostream>
using namespace std;
#define endl '\n'

int C[55][55], D[55][55], N, M, cnt;
int di[8] = {0, 0, -1, 1, 1, 1, -1, -1}, dj[8] = {1, -1, 0, 0, 1, -1, 1, -1};

void init(){
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) C[i][j] = 0, D[i][j] = 0;
    cnt = 0;
}

void dfs(int i, int j){
    C[i][j] = 1;
    for(int k = 0; k < 8; ++k){
        int r = i + di[k], c = j + dj[k];
        if(r < 1 || r > N || c < 1 || c > M) continue;
        if(!C[r][c] && D[i][j]) dfs(r, c);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    while(1){
        cin >> M >> N;
        if(!(N || M)) break;
        init();
        for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) cin >> D[i][j];
        for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j){
            if(!C[i][j] && D[i][j]){
                ++cnt;
                dfs(i, j);
            }
        }
        cout <<  cnt << endl;
    }
    return 0;
}
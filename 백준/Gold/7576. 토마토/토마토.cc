#include<iostream>
#include<utility>
#include<tuple>
#include<queue>
using namespace std;

int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
int toma[1010][1010], N, M, dap, prec, cnt, number, C[1010][1010];
queue<tuple<int, int, int> > q;

void bfs(){
    while(!q.empty()){
        auto [r, c, d] = q.front(); q.pop();
        if(C[r][c]) continue;
        C[r][c] = 1;
        ++cnt;
        for(int k = 0; k < 4; ++k){
            int i = r + di[k], j = c + dj[k];
            if(i < 1 || i > N || j < 1 || j > M) continue;
            if(!toma[i][j]) {
                toma[i][j] = 1;
                q.emplace(i, j, d + 1);
                dap = d + 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> M >> N;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) {
        cin >> toma[i][j];
        if(toma[i][j] != -1) ++number;
        if(toma[i][j] == 1) {
            q.emplace(i, j, 0);
        }
    }
    bfs();
    if(cnt == number) cout << dap;
    else cout << -1;
    return 0;
}
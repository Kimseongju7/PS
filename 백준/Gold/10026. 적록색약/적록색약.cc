#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int C[111][111], P[111][111], dap, N;
int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
queue<pair<int, int> > q;

void bfs(int n){
    ++dap;
    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();
        if(C[r][c]) continue;
        C[r][c] = 1;
        for(int k = 0; k < 4; ++k){
            int i = r + di[k], j = c + dj[k];
            if(P[i][j] == n && !C[i][j]) q.emplace(i, j);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j){
        char t;
        cin >> t;
        if(t == 'R') P[i][j] = 1;
        else if(t == 'G') P[i][j] = 2;
        else P[i][j] = 3;
    }
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j){
        if(!C[i][j]) {
            q.emplace(i, j);
            bfs(P[i][j]);
        }
    }
    cout << dap << ' ';
    dap = 0;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j){
        C[i][j] = 0;
        if(P[i][j] == 2) P[i][j] = 1;
    }
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j){
        if(!C[i][j]) {
            q.emplace(i, j);
            bfs(P[i][j]);
        }
    }
    cout << dap;
    return 0;
}

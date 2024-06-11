#include<iostream>
#include<map>
#include<tuple>
#include<queue>
#define INF 1e9
using namespace std;
int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
char a[22][22], V[22][22];
int R, C;
map<char, int> m;

int dfs(int i, int j){
    int dap = 0;
    if(m[a[i][j]]) return dap;
    ++m[a[i][j]];
    V[i][j] = 1;
    for(int k = 0; k < 4; ++k){
        int r = i + di[k], c = j + dj[k];
        if(r < 1 || c < 1 || r > R || c > C) continue;
        if(!V[r][c]) dap = max(dap, dfs(r, c));
    }
    V[i][j] = 0;
    --m[a[i][j]];
    return dap + 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> R >> C;
    for(int i = 1; i <= R; ++i){
        for(int j = 1; j <= C; ++j) cin >> a[i][j];
    }
    cout << dfs(1, 1);
    return 0;
}
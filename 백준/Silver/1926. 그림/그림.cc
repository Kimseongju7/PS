#include<iostream>
#include<vector>
using namespace std;

int di[4] = {0, 0, -1, 1}, dj[4] = {1, -1, 0, 0}, N, M;
int arr[505][505], C[505][505], cnt, dap, dap2;
void dfs(int i, int j){
    ++cnt;
    C[i][j] = 1;
    for(int k = 0;k <4; ++k){
        int r = i + di[k], c = j + dj[k];
        if(r < 1 || r > N || c < 1 || c > M) continue;
        if(!C[r][c] && arr[r][c]) dfs(r, c);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) cin >> arr[i][j];
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j){
        if(arr[i][j] && !C[i][j]){
            ++dap;
            dfs(i, j);
            dap2 = max(cnt, dap2);
            cnt = 0;
        }
    }
    cout << dap << '\n' << dap2;
    return 0;
}
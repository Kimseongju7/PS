#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl '\n'

int G[30][30], C[30][30], cnt, N, dap;
int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1 , 0, 0};
vector<int> dapL;

void dfs(int i, int j){
    C[i][j] = 1;
    ++cnt;
    for(int k = 0; k < 4; ++k){
        int r = i + di[k], c = j + dj[k];
        if(r < 1 || r > N || c < 1 || c > N) continue;
        if(G[r][c] && !C[r][c]) dfs(r, c);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            char t;
            cin >> t;
            G[i][j] = t - '0';
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            cnt = 0;
            if(G[i][j] && !C[i][j]) {
                dfs(i, j);
                dapL.emplace_back(cnt);
            }
        }
    }
    sort(dapL.begin(), dapL.end());
    cout << dapL.size() << endl;
    for(auto i : dapL) cout << i << endl;
    return 0;
}
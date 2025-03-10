#include<iostream>
#include<queue>
#include<cstring>
#include<utility>
using namespace std;
int N, M, di[4] = {0, 0, -1, 1}, dj[4] = {1, -1, 0, 0};
int A[101][101], C[101][101], tot, dap;
queue<pair<int, int> > q;

void dfs(int r, int c){
    int i, j;
    C[r][c] = 1;
    for(int k = 0; k < 4; ++k){
        i = r + di[k]; j = c + dj[k];
        if(i < 1 || i > N || j < 1 || j > M) continue;
        //치즈이면
        if(A[i][j] && C[i][j] < 2) {
            ++C[i][j];
            if(C[i][j] >= 2) q.emplace(i, j);
        }
        //치즈 아니면
        else if(A[i][j] == 0 && C[i][j] == 0) dfs(i, j);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) {
        cin >> A[i][j];
        if(A[i][j]) ++tot;
    }
    while(tot > 0){
        ++dap;
        memset(C, 0, sizeof(C));
        dfs(1, 1);
        while(!q.empty()){
            auto[i, j] = q.front(); q.pop();
            A[i][j] = 0;
            --tot;
        }
    }
    cout << dap;
    return 0;
}
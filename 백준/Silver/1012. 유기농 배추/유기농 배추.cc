#include<iostream>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl '\n'

int G[55][55], C[55][55], cnt, N, M, T, K;
int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1 , 0, 0};

void init(int N, int M){
    for(int i = 0; i <= N; ++i){
        for(int j = 0; j <= M; ++j) G[i][j] = 0, C[i][j] = 0;
    }
    cnt = 0;
}
vector<int> dapL;

void dfs(int i, int j){
    C[i][j] = 1;
    for(int k = 0; k < 4; ++k){
        int r = i + di[k], c = j + dj[k];
        if(r < 1 || r > N || c < 1 || c > M) continue;
        if(G[r][c] && !C[r][c]) dfs(r, c);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        init(N, M);
        for(int k = 0; k < K; ++k){
            int r, c;
            cin >> c >> r;
            G[r + 1][c + 1] = 1;
        }
        for(int i = 1; i <= N; ++i){
                for(int j = 1; j <= M; ++j){
                    if(!C[i][j] && G[i][j]){
                        ++cnt;
                        dfs(i, j);
                    }
                }
            }
        cout << cnt << endl;
    }
    
    return 0;
}
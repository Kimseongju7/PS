#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
#define INF 1e8;
#define endl '\n'
int N, T;
int D[333][333], C[333][333];
int di[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dj[8] = {1, 2, 2, 1, -1, -2, -2, -1};


void bfs(int i, int j){
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            D[i][j] = INF;
            C[i][j] = 0;
        }
    }
    queue<tuple<int, int, int> > q;
    D[i][j] = 0;
    q.emplace(D[i][j], i, j);
    while(!q.empty()){
        auto [w, i, j] = q.front(); q.pop();
        if(C[i][j]) continue;
        C[i][j] = 1;
        for(int k = 0; k < 8; ++k){
            int r = i + di[k], c = j + dj[k];
            if(r < 1 && r > N && c < 1 && c > N) continue;
            if(D[r][c] > D[i][j] + 1){
                D[r][c] = D[i][j] + 1;
                q.emplace(D[r][c], r, c);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int i, j, r, c;
        cin >> N;
        cin >> i >> j >> r >> c;
        bfs(i + 1, j + 1);
        cout << D[r + 1][c + 1] << endl;
    }
    return 0;
}
#include<iostream>
#include<tuple>
#include<queue>
#define INF 1e9
#define endl '\n'
using namespace std;

int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0}, N, M, x, y;
int arr[1010][1010], D[1010][1010], C[1010][1010];

void bfs(){
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) D[i][j] = -1;
    D[x][y] = 0;
    queue<tuple<int, int, int> > q;
    q.emplace(D[x][y], x, y);
    while(!q.empty()){
        auto [v, i, j] = q.front(); q.pop();
        if(C[i][j]) continue;
        C[i][j] = 1;
        for(int k = 0; k < 4; ++k){
            int r = i + di[k], c = j + dj[k];
            if(r < 1 || r > N || c < 1 || c > M || C[r][c]) continue;
            D[r][c] = v + 1;
            if(arr[r][c]) q.emplace(D[r][c], r, c);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j){
        cin >> arr[i][j];
        if(arr[i][j] == 2) x = i, y = j;
    }
    bfs();
    for(int i = 1; i <= N; ++i) { for(int j = 1; j <= M; ++j){
        if(arr[i][j]) cout << D[i][j] << ' ';
        else cout << 0 << ' ';
    }
    cout << endl;
    }
    return 0;
}
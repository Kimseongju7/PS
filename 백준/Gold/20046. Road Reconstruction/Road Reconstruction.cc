#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
#define INF 1e9
int C[1010][1010], D[1010][1010];
int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
int a[1010][1010], N, M;

void Dijkstra(){
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) D[i][j] = INF;
    D[1][1] = a[1][1];
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> > , greater<> > q;
    q.emplace(D[1][1], 1, 1);
    while(!q.empty()){
        auto [v, i, j] = q.top(); q.pop();
        if(C[i][j]) continue;
        C[i][j] = 1;
        for(int iter = 0; iter < 4; ++iter){
            int r = i + di[iter], c = j + dj[iter];
            if(r < 1 || r > N || c < 1 || c > M || a[r][c] == -1) continue;
            if(D[r][c] > D[i][j] + a[r][c]){
                D[r][c] = D[i][j] + a[r][c];
                q.emplace(D[r][c], r, c);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) cin >> a[i][j];
    if(a[1][1] == -1 || a[N][M] == -1){
        cout << -1;
        return 0;
    }
    Dijkstra();
    if(D[N][M] == INF) cout << -1;
    else cout << D[N][M];
    return 0;
}
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
#define INF 1e9
int mou[30][30], N, M, T, d;
int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0}, dap;
int C[30][30], D[30][30], D2[30][30], s[30][30];

void Dijkstra(){
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) C[i][j] = 0, D[i][j] = INF;
    D[1][1] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<> > q;
    q.emplace(D[1][1], 1, 1);
    while (!q.empty()) {
        auto [p, i, j] = q.top(); q.pop();
        if(C[i][j]) continue;
        C[i][j] = 1;
        for(int k = 0; k < 4; ++k){
            int r = i + di[k], c = j + dj[k], w;
            if(abs(mou[r][c] - mou[i][j]) > T) continue;
            if(mou[r][c] <= mou[i][j]) w = 1;
            else w = (mou[r][c] - mou[i][j]) * (mou[r][c] - mou[i][j]);
            if(D[r][c] > D[i][j] + w){
                D[r][c] = D[i][j] + w;
                q.emplace(D[r][c], r, c);
            }

        }
    }
    
}

int dijkstra(int si, int sj){
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) C[i][j] = 0, D2[i][j] = INF;
    D2[si][sj] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<> > q;
    q.emplace(D2[si][sj], si, sj);
    while (!q.empty()) {
        auto [p, i, j] = q.top(); q.pop();
        if(C[i][j]) continue;
        C[i][j] = 1;
        for(int k = 0; k < 4; ++k){
            int r = i + di[k], c = j + dj[k], w;
            if(abs(mou[r][c] - mou[i][j]) > T) continue;
            if(mou[r][c] <= mou[i][j]) w = 1;
            else w = (mou[r][c] - mou[i][j]) * (mou[r][c] - mou[i][j]);
            if(D2[r][c] > D2[i][j] + w){
                D2[r][c] = D2[i][j] + w;
                q.emplace(D2[r][c], r, c);
            }

        }
    }
    return D2[1][1];
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> T >> d;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j){
        char c;
        cin >> c;
        if('A' <= c && c <= 'Z') mou[i][j] = c - 'A';
        else mou[i][j] = c - 'a' + 26;
    }
    // for(int i = 1; i <= N; ++i){
    //     for(int j = 1; j <= M; ++j) cout << mou[i][j] << ' ';
    //     cout << endl;
    // }
    Dijkstra();
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j) s[i][j] = dijkstra(i, j);
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j){
        if(D[i][j] + s[i][j] > d) continue;
        if(dap < mou[i][j]) {
            //cout << D[i][j] + s[i][j] << endl;
            dap = mou[i][j];
        }
    }
    cout << dap;
    return 0;
}
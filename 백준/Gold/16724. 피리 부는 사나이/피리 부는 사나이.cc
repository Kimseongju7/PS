#include<iostream>
#include<utility>
using namespace std;
pair<int, int> P[1010][1010];
int N, M, map[1010][1010], C[1010][1010], dap;
int di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, 1, -1};
enum {U, D, R, L};

void init(){
    for(int i = 0; i <= N; ++i) for(int j = 0; j <= M; ++j) P[i][j] = {i, j};
}

pair<int, int> Find(int u, int v){
    if(u == P[u][v].first && v == P[u][v].second) return P[u][v];
    else return P[u][v] = Find(P[u][v].first, P[u][v].second);
}

void Union(pair<int, int> u, pair<int, int> v){
    u = Find(u.first, u.second); v = Find(v.first, v.second);
    if(u == v) return;
    P[u.first][u.second] = v;
}

void dfs(int i, int j){
    C[i][j] = 1;
    int r = i + di[map[i][j]], c = j + dj[map[i][j]];
    if(r < 1 || r > N || c < 1 || c > M) return;
    Union({i, j}, {r, c});
    if(!C[r][c]) dfs(r, c);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= M; ++j){
        char t;
        cin >> t;
        switch (t)
        {
            case 'U':
                map[i][j] = U;
                break;
            case 'D' :
                map[i][j] = D;
                break;
            case 'R' :
                map[i][j] = R;
                break;
            case 'L' :
                map[i][j] = L;
                break;
        }
    }
    init();
    for(int i = 1; i<= N; ++i) for(int j = 1; j <= M; ++j){
        if(!C[i][j]) dfs(i, j);
    }
    //for(int i = 1; i<= N; ++i) for(int j = 1; j <= M; ++j) cout << P[i][j].first << ' ' << P[i][j].second << endl;
    for(int i = 1; i<= N; ++i) for(int j = 1; j <= M; ++j){
        if(Find(0, 0) != Find(i, j)){
            ++dap;
            Union({i, j}, {0, 0});
        }
    }
    cout << dap;
    return 0;
}
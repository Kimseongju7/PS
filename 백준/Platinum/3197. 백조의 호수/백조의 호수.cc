#include<iostream>
#include<utility>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;



pair<int, int> P[1515][1515];
vector<pair<int,int> > swan;
int R, C, dap = -1, river[1515][1515], Ci[1515][1515];
int di[4] = {0, 0, -1, 1}, dj[4] = {1, -1, 0, 0}, number = 1;

void init() {
    for(int i = 1; i <= R; ++i){
        for(int j = 1; j <= C; ++j) P[i][j] = {i, j}, Ci[i][j] = -1;
    }
}
pair<int, int> Find(pair<int, int> v){
    if(P[v.first][v.second] == v) return v;
    else return P[v.first][v.second] = Find({P[v.first][v.second]});
}
void Union(pair<int, int> u, pair<int, int> v){
    u = Find(u); v = Find(v);
    if(u == v) return;
    P[v.first][v.second] = u;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> R >> C;
    init();
    for(int i = 1; i <= R; ++i) for(int j = 1; j <= C; ++j){
        char t;
        cin >> t;
        if(t == '.') river[i][j] = 1, Ci[i][j] = number;
        else if(t == 'X') river[i][j] = 0;
        else {
            river[i][j] = 2; Ci[i][j] = number;
            swan.emplace_back(i, j);
        }
    }
    for(int i = 1; i <= R; ++i) for(int j = 1; j <= C; ++j){
        for(int k = 0; k < 4; ++k){
            int r = i + di[k], c = j + dj[k];
            if(r < 1 || r > R || c < 1 || c > C) continue;
            if(!river[r][c]) continue;
            if(river[i][j] == river[r][c]) Union({i, j}, {r, c});
        }
    }
    while(1){
        ++dap;
        for(int k = 0; k < 4; ++k){
            int r0 = swan[0].first + di[k], c0 = swan[0].second + dj[k], r1 = swan[1].first + di[k], c1 = swan[1].second + dj[k];
            if(!(r0 < 1 || r0 > R || c0 < 1 || c0 > C)) if(river[r0][c0]) Union(swan[0], {r0, c0});
            if(!(r1 < 1 || r1 > R || c1 < 1 || c1 > C)) if(river[r1][c1]) Union(swan[1], {r1, c1});
        }
        if(Find(swan[0]) == Find(swan[1])){
            cout << dap;
            break;
        }
        for(int i = 1; i <= R; ++i) for(int j = 1; j <= C; ++j){
            if(Ci[i][j] == number && river[i][j]){
                for(int k = 0; k < 4; ++k){
                    int r = i + di[k], c = j + dj[k];
                    if(r < 1 || r > R || c < 1 || c > C) continue;
                    if(!river[r][c]) {
                        river[r][c] = 1; Ci[r][c] = number + 1;
                        for(int l = 0; l < 4; ++l){
                            int r1 = r + di[l], c1 = c + dj[l];
                            if(r < 1 || r > R || c < 1 || c > C) continue;
                            if(river[r1][c1]) Union({r1, c1}, {r, c});
                        }
                    }
                    Union({i, j}, {r, c});
                }
            }
        }
        ++number;
    }
    return 0;
}

#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
#define INF 1e9
int D[1010101], C[1010101], f, g, s, u, d;
vector<int> G[1010101];

void bfs(){
    for(int i = 1; i <= f; ++i) D[i] = INF;
    queue<pair<int, int> > q;
    D[s] = 0;
    q.emplace(0, s);
    while(!q.empty()){
        auto [c, v] = q.front(); q.pop();
        if(C[v]) continue;
        C[v] = 1;
        for(auto i : G[v]){
            if(D[i] > D[v] + 1){
                D[i] = c + 1;
                q.emplace(D[i], i);
            }
        }
    }
}  

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> f >> s >> g >> u >> d;
    for(int i = 1; i <= f; ++i){
        int up = i + u, down = i - d;
        if(up >= 1 && up <= f) G[i].emplace_back(up);
        if(down >= 1 && down <= f) G[i].emplace_back(down);
    }
    bfs();
    if(D[g] == INF) cout << "use the stairs";
    else cout << D[g];
    return 0;
}
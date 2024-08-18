#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
int D[111], C[111], N, M, s, e;
vector<int> G[111];

void bfs(){
    for(int i = 1; i <= N; ++i) D[i] = -1;
    D[s] = 0;
    queue<pair<int, int> > q; 
    q.emplace(D[s], s);
    while(!q.empty()){
        auto [c, v] = q.front(); q.pop();
        if(C[v]) continue;
        C[v] = 1;
        for(auto i : G[v]){
            if(C[i]) continue;
            D[i] = D[v] + 1;
            q.emplace(D[i], i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    cin >> s >> e;
    cin >> M;
    for(int i = 0; i < M; ++i){
        int u, v;
        cin >> u >> v;
        G[v].emplace_back(u);
        G[u].emplace_back(v);
    }
    bfs();
    cout << D[e];
    return 0;
}
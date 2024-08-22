#include<iostream>
#include<queue>
using namespace std;
#define INF 1e9
#define endl '\n'
#include<utility>
int C[1010], D[1010];
vector<pair<int, int> > G[1010];
int N, M;

void init(){for(int i = 1; i <= N; ++i) C[i] = 0, D[i] = INF;}

void bfs(int s){
    init();
    D[s] = 0;
    queue<pair<int, int> > q;
    q.emplace(D[s], s);
    while(!q.empty()){
        auto [c, v] =  q.front(); q.pop();
        if(C[v]) continue;
        C[v] = 1;
        for(auto [i, w] : G[v]){
            if(!C[i]){
                D[i] = D[v] + w;
                q.emplace(D[i], i);
            }
        }
    }
}

int main(){ 
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i < N; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    for(int i = 0; i < M; ++i){
        int u, v; cin >> u >> v;
        bfs(u);
        cout << D[v] << endl;
    }

    return 0;
}
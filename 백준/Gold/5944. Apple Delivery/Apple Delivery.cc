#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define INF (1e9 + 1e9)

int C[101010], D[101010], dapab, dapba, N, M, a, b, p;
vector<pair<int, int> > G[101010];

void Dijkstra(int s){
    for(int i = 1; i <= N; ++i) C[i] = 0, D[i] = INF;
    D[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > q;
    q.emplace(D[s], s);
    while(!q.empty()){
        auto [c, v] = q.top(); q.pop();
        if(C[v]) continue;
        C[v] = 1;
        for(auto [i, w] : G[v]){
            if(D[i] > D[v] + w){
                D[i] = D[v] + w;
                q.emplace(D[i], i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> M >> N >> p >> a >> b;
    for(int i = 0; i < M; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    Dijkstra(p);
    dapab = D[a];
    dapba = D[b];
    Dijkstra(a);
    dapab += D[b];
    Dijkstra(b);
    dapba += D[a];
    cout << min(dapab, dapba);
    return 0;
}
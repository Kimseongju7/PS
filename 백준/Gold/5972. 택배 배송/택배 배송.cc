#include<iostream>
#include<queue>
#include<utility>
#define INF 1e9
#define endl '\n'
using namespace std;
int C[50101], D[50101], N, M;
vector<pair<int, int> > G[50101];


void Dijkstra(){
    for(int i = 1; i <= N; ++i) C[i] = 0, D[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > q;
    D[1] = 0;
    q.emplace(D[1], 1);
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
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    Dijkstra();
    cout << D[N];
    return 0;
}
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define INF 1e9
#define endl '\n'
int D[1010], C[1010], N, M, sum, mins, mini, P[1010];
vector<pair<int, int> > G[1010];

void Dijkstra(int s){
    sum = 0;
    for(int i = 1; i <= N; ++i) C[i] = 0, D[i] = INF;
    D[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> > , greater<> > pq;
    pq.emplace(D[s], s);
    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(C[v]) continue;
        C[v] = 1;
        for(auto [i, w] : G[v]){
            if(D[i] > D[v] + w){
                D[i] = D[v] + w;
                P[i] = v;
                pq.emplace(D[i], i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    Dijkstra(1);
    cout << N - 1 << endl;
    for(int i = 2; i <= N; ++i) cout << P[i] << ' ' << i << endl;
    return 0;
}
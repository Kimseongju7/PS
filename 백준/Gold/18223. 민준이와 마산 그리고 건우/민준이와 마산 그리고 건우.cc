#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define INF 1e9

int D[5050];
int C[5050], N, M, p, mins, sum;
vector<pair<int, int> > G[5050];

void Dijkstra(int s){    
    for(int i = 1; i <= N; ++i) D[i] = INF, C[i] = 0;
    D[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    pq.emplace(D[s], s);
    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(C[v]) continue;
        C[v] = 1;
        for(auto [i, w] : G[v]){
            if(D[i] > D[v] + w){
                D[i] = D[v] + w;
                pq.emplace(D[i], i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> p;
    for(int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    Dijkstra(1);
    mins = D[N]; sum = D[p];
    Dijkstra(p);
    sum += D[N];
    if(sum == mins) cout << "SAVE HIM";
    else cout << "GOOD BYE";
    return 0;
}
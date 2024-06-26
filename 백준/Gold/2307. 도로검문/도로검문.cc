#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define INF 1e9

int D[1010], C[1010], N, M, dap, org, P[1010];
vector<pair<int, int>> p;
vector<pair<int, int> > G[1010];
bool b = true;

void Dijkstra(const pair<int, int> &p = {0, 0}){
    for(int i = 1; i <= N; ++i) C[i] = 0, D[i] = INF;
    D[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > q;
    q.emplace(D[1], 1);
    while(!q.empty()){
        auto [c, v] = q.top(); q.pop();
        if(C[v]) continue;
        C[v] = 1;
        for(auto [i, w] : G[v]){
            if((p.first == v && p.second == i) || (p.first == i && p.second == v)) continue;
            if(D[i] > D[v] + w){
                D[i] = D[v] + w;
                P[i] = v;
                q.emplace(D[i], i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        int u, v, w; 
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    Dijkstra();
    org = D[N];
    for(int i = N; P[i]; i = P[i]) p.emplace_back(i, P[i]);
    for(int i = 0; i <= p.size(); ++i){
        Dijkstra(p[i]);
        if(D[N] == INF) b = false;
        else{
            dap = max(dap, D[N] - org);
        }
        //cout << D[N] << endl;
    }
    //cout << org << endl;
    if(b) cout << dap;
    else cout << -1;
    return 0;
}
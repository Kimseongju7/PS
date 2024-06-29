#include<iostream>
#include<queue>
#include<utility>
#define INF 1e9
#define endl '\n'
using namespace std;
int C[10101], D[10101], T, N, M, s;

void Dijkstra(int s, vector<pair<int, int> > G[10101]){
    for(int i = 1; i <= N; ++i) C[i] = 0, D[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > q;
    D[s] = 0;
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
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> s;
        int cnt = 0, maxTime = 0;
        {
            vector<pair<int, int> > G[N + 1];
            for(int i = 0; i < M; ++i){
                int u, v, w;
                cin >> v >> u >> w;
                G[u].emplace_back(v, w);
            }
            Dijkstra(s, G);
            for(int i = 1; i <= N; ++i){
                if(D[i] == INF) ;
                else{
                    ++cnt;
                    if(D[i] > maxTime) maxTime = D[i];
                }
            }
            cout << cnt << ' ' << maxTime << endl;
        }
    }
    
    return 0;
}
#include<iostream>
#include<queue>
#include<utility>
#define INF 1e9
using namespace std;
int D[111], C[111];
vector<int> G[111];
int N ,M, dap = INF, sum, dapi;
void Dijkstra(int s){
    for(int i = 1; i <= N; ++i) D[i] = INF, C[i] = 0;
    D[s] = 0;
    priority_queue<pair<int, int> > q;
    q.emplace(D[s], s);
    while(!q.empty()){
        auto [c, v] = q.top(); q.pop();
        if(C[v]) continue;
        C[v] = 1;
        for(auto i : G[v]){
            if(D[i] > D[v] + 1){
                D[i] = D[v] + 1;
                q.emplace(D[i], i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i< M; ++i){
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for(int i =1 ; i <= N; ++i){
        sum = 0;
        Dijkstra(i);
        for(int j = 1; j <= N; ++j) sum += D[j];
        if(sum < dap){
            dapi = i;
            dap = sum;
        }
    }
    cout << dapi;
    return 0;
}
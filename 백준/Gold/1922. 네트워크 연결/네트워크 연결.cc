#include<iostream>
#include<queue>
#include<utility>
using namespace std;

vector<pair<int, int> > G[1010];
int C[1010], N, M;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    C[1] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    int dap = 0;
    for(auto [i, w] : G[1]) pq.emplace(w, i);
    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(C[v]) continue;
        C[v] = 1; dap += c;
        for(auto [i, w] : G[v]) pq.emplace(w, i);
    }
    cout << dap;
    return 0;
}
#include<iostream>
#include<queue>
#include<utility>
using namespace std;

vector<pair<int, int> > G[101010];
int N, M, dap, maxm, C[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i =1; i <= M; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    C[1] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    for(auto [i, w] : G[1]) pq.emplace(w, i);
    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(C[v]) continue;
        C[v] = 1; dap += c; maxm = max(maxm, c);
        for(auto [i, w] : G[v]) pq.emplace(w, i);
    }
    cout << dap - maxm;
    return 0;
}
#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;
#define endl '\n'
#define N 100000
#define INF 1e9
vector<pair<int, int> > G[202020];
vector<int> path;
int s, k;
int D[202020], C[202020], P[202020];

void Dijkstra(){
    for(int i = 0; i < 202020; ++i) D[i] = INF, C[i] = 0, P[i] = -1;
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
                P[i] = v;
                pq.emplace(D[i], i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s >> k;
    G[0].emplace_back(1, 1);
    for(int i = 1; i <= N; ++i){
        G[i].emplace_back(i - 1, 1);
        G[i].emplace_back(i + 1, 1);
        G[i].emplace_back(2 * i, 1);
    }
    Dijkstra();
    cout << D[k] << '\n';
    for(int i = k; i != -1; i = P[i]) path.emplace_back(i);
    reverse(path.begin(), path.end());
    for(auto i : path) cout << i << ' ';
    return 0;
}
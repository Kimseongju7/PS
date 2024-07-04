#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
#define INF 1e9
#define endl '\n'
long long D[505], N, M;
vector<tuple<int, int, int> > G;

bool BellmanFord(int S){
    for(int i = 0; i <= N; ++i) D[i] = INF;
    D[S] = 0;
    for(int iter = 1; iter <= N; ++iter){
        bool change = false;
        for(auto [s, e, w] : G){
            if(D[s] == INF) continue;
            if(D[e] > D[s] + w){
                change = true;
                D[e] = D[s] + w;
            }
        }
        if(iter == N && change) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        G.emplace_back(u, v, w);
    }
    if(BellmanFord(1)){
        for(int i = 2; i <= N; ++i) if(D[i] == INF) cout << -1 << endl; else cout << D[i] << endl;
    }
    else cout << -1;
    return 0;
}
#include<iostream>
#include<vector>
#include<tuple>
#define endl '\n'
using namespace std;
#define INF 1e9

int T, N, M, W;
vector<tuple<int, int, int> > G;
long long D[555];
int C[555];

bool bellmanFord(){
    for(int i = 1; i <= N; ++i) D[i] = INF, C[i] = 0;
    for(int i = 1; i <= N; ++i){
        if(C[i]) continue;
        D[i] = 0; C[i] = 1;
        for(int iter = 1; iter <= N; ++iter){
            bool isChanged = false;
            for(auto [s, e, w] : G){
                if(D[s] == INF) continue;
                if(D[e] > D[s] + w){
                    C[e] = 1;
                    D[e] = D[s] + w;
                    isChanged = true;
                }
            }
            if(iter == N && isChanged) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while(T--){
        cin >> N >> M >> W;
        for(int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            G.emplace_back(u, v, w);
            G.emplace_back(v, u, w);
        }
        for(int i = 0; i < W; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            G.emplace_back(u, v, -w);
        }
        if(bellmanFord()) cout << "NO" << endl;
        else cout << "YES" << endl;
        G.clear();
    }
    return 0;
}
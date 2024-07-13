#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
#define INF 1e18
long long D[111];
int N, M, P[111], U[111], C1[111], C2[111];
vector<tuple<int, int, int> > G;
vector<int> G1[111], G2[111];

void dfs1(int s){
    ++U[s];
    C1[s] = 1;
    for(auto i : G1[s]) if(!C1[i]) dfs1(i);
}

void dfs2(int s){
    ++U[s];
    C2[s] = 1;
    for(auto i : G2[s]) if(!C2[i]) dfs2(i);
}

bool bellmanFord(int S){
    for(int i = 1; i <= N; ++i) D[i] = INF;
    D[S] = 0;
    for(int iter = 1; iter <= N; ++iter){
        bool isChanged = false;
        for(auto [s, e, w] : G){
            if(D[s] == INF) continue;
            if(D[e] > D[s] + w && U[s] == 2){
                isChanged = true;
                D[e] = D[s] + w;
                P[e] = s;
            }
        }
        if(iter == N && isChanged) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        int s, e, w;
        cin >> s >> e >> w;
        G.emplace_back(s, e, -w);
        G1[s].emplace_back(e);
        G2[e].emplace_back(s);
    }
    dfs1(1);
    dfs2(N);
    vector<int> dap;
    if(bellmanFord(1)) {
        for(int i = N; i; i = P[i]) dap.emplace_back(i);
        for(auto i = dap.rbegin(); i != dap.rend(); ++i) cout << *i << ' ';
        
    }
    else cout << -1;
    return 0;
}



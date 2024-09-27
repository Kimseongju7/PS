#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1e9
#define endl '\n'
using namespace std;
int N, D[101][101], M, P[101], dap[101], tot[101];

int Find(int v){
    if(P[v] == v) return v;
    else return P[v] = Find(P[v]);
}

void Union(int u, int v){
    u = Find(u); v = Find(v);
    P[u] = v;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i = 1; i <= N; ++i) D[i][i] = 0, P[i] = i;
    for(int i = 1; i <= M; ++i){
        int u, v; cin >> u >> v;
        D[u][v] = 1; D[v][u] = 1;
    }
    for(int k = 1; k <= N; ++k) for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) {
        if(D[i][j] != INF) Union(i, j);
    }
    for(int i = 1; i <= N; ++i) tot[i] = INF;
    for(int i = 1; i <= N; ++i){
        int m = 0;
        for(int j = 1; j <= N; ++j){
            if(Find(i) == Find(j)){
                m = max(m, D[i][j]);
            }
        }
        if(tot[Find(i)] > m){
            dap[Find(i)] = i;
            tot[Find(i)] = m;
        }
    }
    vector<int> ddap;
    for(int i = 1; i <= N; ++i) {
        if(dap[i] != 0) ddap.emplace_back(dap[i]);
    }
    sort(ddap.begin(), ddap.end());
    cout << ddap.size() << endl;
    for(auto i : ddap) cout << i << endl;
    
    return 0;
}
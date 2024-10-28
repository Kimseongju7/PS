#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int P[1010], S[1010], N, M, K;
vector<tuple<int, int, int> > E;

void init(){for(int i = 1; i <= N; ++i) P[i] = i, S[i] = 1;}
int Find(int v){return v == P[v] ? v : Find(P[v]);}
void Union(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) return;
    if(S[u] > S[v]) swap(u, v);
    P[u] = v; S[v] += S[u];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> K;
    init();
    for(int i = 1; i <= K; ++i){
        int k; cin >> k;
        P[k] = 0;
    }
    for(int i = 1; i <= M; ++i){
        int u, v, w; cin >> u >> v >> w;
        E.emplace_back(w, u, v);
    }
    sort(E.begin(), E.end());
    S[0] = K + 1;
    int dap = 0;
    for(auto [w, u, v] : E){
        if(S[0] == N + 1) break;
        if(Find(u) != Find(v)){
            Union(u, v);
            dap += w;
        }
    }
    cout << dap;
    return 0;
}
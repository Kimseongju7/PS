#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
using namespace std;

int N, M, K;
vector<tuple<int, int, int> > E;
int C[10101], P[10101];

void init(){for(int i = 1; i <= N; ++i) P[i] = i;}
int Find(int v){return v == P[v] ? v : P[v] = Find(P[v]);}
bool Union(int u, int v){return Find(u) != Find(v) && (P[P[u]] = P[v], true); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> K;
    for(int i = 1; i <= M; ++i){
        int u, v; cin >> u >> v;
        E.emplace_back(i, u, v);
    }
    init();
    sort(E.begin(), E.end());
    for(int i = 0; i < K; ++i){
        int cnt = 0, dap = 0;
        init();
        for(auto [w, u, v] : E) {
            if(C[w]) continue;
            if(Union(u, v)){
                dap += w; ++cnt;
            }
        }
        if(cnt == (N - 1)) cout << dap << ' ';
        else cout << 0 << ' ';
        C[get<0>(E[i])] = 1; 
    }
    return 0;
}
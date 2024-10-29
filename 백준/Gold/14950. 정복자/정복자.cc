#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int N, M, t, P[10101];
vector<tuple<int, int, int> > E;

void init(){for(int i = 1; i <= N; ++i) P[i] = i;}
int Find(int v){
    return v == P[v] ? v : P[v] = Find(P[v]);
}
bool Union(int u, int v){
    return Find(u) != Find(v) && (P[P[u]] = P[v], true);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> t;
    init();
    int dap = 0, cnt = 0;
    for(int i = 1; i<=M; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        E.emplace_back(w, u, v);
    }
    sort(E.begin(), E.end());
    for(auto [w, u, v] : E){
        if(Union(u, v)) {
            dap += w + t * cnt;
            ++cnt;
        }
    }
    cout << dap;
    return 0;
}

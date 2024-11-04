#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int P[55], N, M;
vector<tuple<int, int, int> > E;

void init(){
    for(int i = 1; i <= N; ++i) P[i] = i;
    E.clear();
}

int Find(int v) { return v == P[v] ? v : P[v] = Find(P[v]);}
bool Union(int u, int v){ return Find(u) != Find(v) && (P[P[u]] = P[v], true);}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    while(true){
        cin >> N;
        if(!N) break;
        cin >> M;
        init();
        for(int i = 1; i <= M; ++i){
            int u, v, w; cin >> u >> v >> w;
            E.emplace_back(w, u, v);
        }
        sort(E.begin(), E.end());
        int dap = 0;
        for(auto [w, u, v] : E){
            if(Union(u, v)) dap += w;
        }
        cout << dap << '\n';
    }
    return 0;
}
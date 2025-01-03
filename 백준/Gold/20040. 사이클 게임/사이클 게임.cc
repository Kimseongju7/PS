#include<iostream>
using namespace std;

int P[505050], N;

void init(){for(int i = 1; i <= N; ++i) P[i] = i;}
int Find(int v){return v == P[v] ? v : (P[v] = Find(P[v]));}
void Union(int u, int v){
    u = Find(u); v = Find(v);
    P[u] = v;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int M, dap = 0, u, v; cin >> N >> M;
    init();
    for(int i = 1; i <= M; ++i){
        cin >> u >> v;
        if(Find(u) == Find(v)) {
            dap = i;
            break;
        }
        Union(u, v);
    }
    cout << dap;
    return 0;
}
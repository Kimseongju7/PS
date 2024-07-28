#include<iostream>
#include<cstdlib>
using namespace std;
int P[10101], M[10101], N, m, K, dap;

void init(){ for(int i = 0; i <= N; ++i) P[i] = i; }
int Find(int v) {
    if(v == P[v]) return v;
    return P[v] = Find(P[v]);
}
void Union(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) return;
    if(M[u] < M[v]) swap(u, v);
    P[u] = v;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> m >> K;
    init();
    for(int i = 1; i <= N; ++i) {
        int t;
        cin >> t;
        M[i] = t;
    }
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    for(int i = 1; i <= N; ++i){
        if(Find(i) != 0){
            dap += M[Find(i)];
            K -= M[Find(i)];
            if(K < 0){
                cout << "Oh no";
                return 0;
            }
            Union(0, Find(i));
        }
    }
    cout << dap;
    return 0;
}
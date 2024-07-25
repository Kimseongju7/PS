#include<iostream>
#define endl '\n'
using namespace std;

int P[1010101];
int N, M;

void init(){
    for(int i = 0; i <= N; ++i) P[i] = i;
}

int Find(int v){
    if(v == P[v]) return v;
    else return P[v] = Find(P[v]);
}

void Union(int u, int v){
    u = Find(u);
    v = Find(v);
    P[u] = v;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    init();
    for(int i = 0; i < M; ++i){
        int u, v, p;
        cin >> p >> u >> v;
        if(!p) Union(u, v);
        else {
            if(Find(u) == Find(v)) cout << "YES" << endl; else cout << "NO" << endl;
        }
    }
    return 0;
}
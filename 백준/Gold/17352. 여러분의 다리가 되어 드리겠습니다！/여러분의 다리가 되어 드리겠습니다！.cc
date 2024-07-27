#include<iostream>
using namespace std;

int N, P[303030]; 

void init() { for(int i = 1; i <= N; ++i) P[i] = i; }
int Find(int v){
    if(v == P[v]) return v;
    else return P[v] = Find(P[v]);
}
void Union(int u, int v){ P[Find(u)] = Find(v); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    int u, v;
    init();
    for(int i = 2; i < N; ++i){
        cin >> u >> v;
        Union(u, v);
    }
    for(int i = 2; i <= N; ++i) {
        if(Find(1) != Find(i)) {
            cout << 1 << ' ' << i;
            break;
        }
    }
    return 0;
}
#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
int P[1010101];


int Find(int v){ return v == P[v] ? v : (P[v] = Find(P[v])); }
void Union(int u, int v){ P[Find(u)] = Find(v); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T, N, K, M;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        cin >> N;
        for(int i = 0; i < N; ++i) P[i] = i;
        cin >> M;
        while(M--){
            int u, v; cin >> u >> v;
            Union(u, v);
        }
        cin >> M;
        cout << "Scenario " << t << ":\n";
        while(M--){
            int u, v; cin >> u >> v;
            if(Find(u) == Find(v)) cout << 1 << endl;
            else cout << 0 << endl;
        }
        cout << endl;
    }
    
    return 0;
}
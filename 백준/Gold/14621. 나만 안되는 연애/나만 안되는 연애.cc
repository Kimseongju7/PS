#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int P[10101], N, M;
bool S[10101];
vector<tuple<int, int, int> > E;

void init(){for(int i = 1; i <= N; ++i) P[i] = i;}
int Find(int v){return v == P[v] ? v : P[v] = Find(P[v]);}
bool Union(int u, int v){ return Find(u) != Find(v) && (P[P[u]] = P[v], true);}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    init();
    for(int i = 1; i <= N; ++i){
        char c; cin >> c;
        S[i] = c == 'W' ? true : false;
    }
    for(int i = 1 ;i <= M; ++i){
        int u, v, d; cin >> u >> v >> d;
        if(S[u] != S[v]) E.emplace_back(d, u, v);
    }
    int dap = 0, cnt = 0;
    sort(E.begin(), E.end());
    for(auto [w, u, v] : E){
        if(Union(u, v)) dap += w, ++cnt;
    }
    if(cnt == (N - 1) )cout << dap;
    else cout << -1;
    return 0;
}
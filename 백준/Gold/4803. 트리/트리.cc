#include<iostream>
#include<utility>
#define endl '\n'
using namespace std;
int P[555];
int N, M, dap, Case = 0;
pair<int, int> S[555];

void init(){
    for(int i = 0; i <= N; ++i) P[i] = i, S[i].first = 1, S[i].second = 0;
    dap = 0;
    S[0].first = 555;
}

int Find(int v){
    if(P[v] == v) return v;
    else return Find(P[v]);
}

void Union(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) {
        S[u].second += 1;
        return;
    }
    if(S[u] > S[v]) swap(u, v);
    P[u] = v;
    S[v].first += S[u].first;
    S[v].second += S[u].second + 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    while(1){
        cin >> N >> M;
        if(!(N || M)) break;
        init(); ++Case;
        for(int i = 1; i <= M; ++i){
            int u, v;
            cin >> u >> v;
            Union(u, v);
        }
        for(int i = 1; i <= N; ++i) if(Find(0) != Find(i)){
            if(S[Find(i)].first == S[Find(i)].second + 1) ++dap;
            //cout << endl << i << ' ' << S[Find(i)].first << ' ' << S[Find(i)].second << endl;
            Union(0, Find(i));
        }
        cout << "Case " << Case << ": ";
        if(dap == 0) cout << "No trees.";
        else if(dap == 1) cout << "There is one tree.";
        else cout << "A forest of " << dap << " trees.";
        cout << endl;
    }  
    return 0;
}
#include<iostream>
#include<vector>
#include<tuple>
#define INF 1e18
using namespace std;
vector<tuple<int, int, int> > G;
vector<int> G2[55], G3[55];
long long D[55], N, M, money[55];
int E, U[55], C2[55], C3[55];

void dfs2(int s){
    C2[s] = 1;
    U[s] += 1;
    for(auto i : G2[s]) if(!C2[i]) {
        dfs2(i);
    }
}

void dfs3(int s){
    C3[s] = 1;
    U[s] += 2;
    for(auto i : G3[s]){
        if(!C3[i]){
            dfs3(i);
        }
    }
}


bool BellmanFord(int S){
    for(int i = 0; i <= N; ++i) D[i] = INF;
    D[S] = -money[S];
    for(int iter = 1; iter <= N + N; ++iter){
        bool ch = false;
        for(auto [s, e, w] : G){
            if(D[s] == INF || U[s] != 3) continue;
            if(D[e] > D[s] + w - money[e]){
                ch = true;
                D[e] = D[s] + w - money[e];
            }
        }
        if(iter == N + N && ch) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int s;
    cin >> N >> s >> E >> M;
    for(int i = 0; i < M; ++i){
        int s, e, w;
        cin >> s >> e >> w;
        G.emplace_back(s, e, w);
        G2[s].emplace_back(e);
        G3[e].emplace_back(s);
    }
    dfs2(s);
    dfs3(E);
    for(int i = 0; i< N; ++i) cin >> money[i];
    //for(int i = 0; i < N ;++i) cout << U[i] << ' ';
    //cout << endl;
    if(BellmanFord(s)) {
        //cout << D[E] << endl;
        if(D[E] == INF) cout << "gg";
        else cout << -D[E];
    }
    else {
        //cout << D[E] << endl;
        cout << (D[E] == INF ? "gg" : "Gee");
    }
    return 0;
}
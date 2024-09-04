#include<iostream>
#include<vector>
using namespace std;
#define INF 1e9
#define endl '\n'
int D[111][111], N, M, P[111][111];

void recursion(vector<int> &v, int s, int e){
    if(P[s][e] == 0) return;
    recursion(v, s, P[s][e]);
    v.emplace_back(P[s][e]);
    recursion(v, P[s][e], e);
}

vector<int> getPath(int s, int e){
    vector<int> v;
    if(s == e || D[s][e] == INF) return v;
    v.emplace_back(s);
    recursion(v, s, e);
    v.emplace_back(e);
    return v;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i = 1; i <= N; ++i) D[i][i] = 0;
    for(int i = 1; i <= M; ++i) {
        int s, e, w; cin >> s >> e >> w;
        D[s][e] = min(D[s][e], w);
    }
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                if(D[i][j] > D[i][k] + D[k][j]) P[i][j] = k;
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(D[i][j] == INF) cout << 0;
            else cout << D[i][j];
            cout << ' ';
        }
        cout << endl;
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            vector<int> v = getPath(i, j);
            cout << v.size() << ' ';
            for(auto iter : v) cout << iter << ' ';
            cout << endl;
        }
    }
    return 0;
}
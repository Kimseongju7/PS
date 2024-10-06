#include<iostream>
#include<utility>
using namespace std;
#define INF 1e9
int D[303][303], N, Q;
pair<int, int> line[303];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i <= N; ++i){
        int a, b; cin >> a >> b;
        line[i] = {a, b};
    }
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i  = 1; i <= N; ++i) D[i][i] = 0;
    for(int i = 1 ;i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(i == j) continue;
            if(line[i].first <= line[j].second && line[i].second >= line[j].first) D[i][j] = 1, D[j][i] = 1;
            else if(line[i].second >= line[j].first && line[i].first <= line[j].second) D[i][j] = 1, D[j][i] = 1;
            else if (line[i].first <= line[j].first && line[i].second >= line[j].second) D[i][j] = 1, D[j][i] = 1;
        }
    }
    for(int k = 1; k <= N; ++k) for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    cin >> Q;
    while(Q--){
        int s, e; cin >> s >> e;
        cout << ((D[s][e] == INF) ? -1 : D[s][e]) << '\n';
    }
    return 0;
}
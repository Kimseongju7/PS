#include<iostream>
#include<vector>
using namespace std;
#define INF 1e9
int D[202][202], N, M, K, tmpTime, minTime = INF, times[202];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1;i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
    for(int i = 1; i <= N; ++i) D[i][i] = 0;
    for(int i = 1; i <= M; ++i){
        int s, e, w; cin >> s >> e >> w;
        D[s][e] = min(D[s][e], w);
    }
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    cin >> K;
    vector<int> v(K);
    for(auto &i : v) cin >> i;
    for(int i = 1; i <= N; ++i){
        tmpTime = 0;
        for(auto f : v){
            tmpTime = max(tmpTime, D[f][i] + D[i][f]);
        }
        times[i] = tmpTime;
    }
    for(int i = 1; i <= N; ++i){
        minTime = min(minTime, times[i]);
    }
    for(int i = 1 ; i <= N; ++i){
        if(minTime == times[i]) cout << i << ' ';
    }
    //cout << endl << minTime << endl;
    //for(int i = 1; i <= N; ++i) cout << times[i] << ' ';
    return 0;
}
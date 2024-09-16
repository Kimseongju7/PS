#include<iostream>
#include<vector>
#define INF 1e9
using namespace std;
#define endl '\n'
int D[111][111], M, K, T, N;
int dap, dapi, sum;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while(T--){
        dap = INF;
        cin >> N >> M;
        for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) D[i][j] = INF;
        for(int i = 1; i <= N; ++i) D[i][i] = 0;
        for(int i = 1; i <= M; ++i){
            int u, v, w; cin >> u >> v >> w;
            D[u][v] = min(D[u][v], w);
            D[v][u] = min(D[v][u], w);
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
            sum = 0;
            for(auto v : v){
                sum += D[v][i];
            }
            if(sum < dap){
                dap = sum; dapi = i;
            }
        }
        cout << dapi << endl;
    }
    return 0;
}
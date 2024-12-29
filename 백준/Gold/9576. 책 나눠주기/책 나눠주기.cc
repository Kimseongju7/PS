#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int G[1010][2], visitNum, C[1010], A[1010];

int dfs(int v){
    for(int i = G[v][0]; i <= G[v][1]; ++i){
        if(C[i] == visitNum) continue;
        C[i] = visitNum;
        if(A[i] == 0 || dfs(A[i])){
            A[i] = v;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T, N, M, dap; cin >> T;
    while(T--){
        visitNum = 1;
        dap = 0;
        memset(G, 0, sizeof(G));
        memset(C, 0, sizeof(C));
        memset(A, 0, sizeof(A));
        cin >> M >> N;
        for(int i = 1; i <= N; ++i){
            int a, b; cin >> a >> b;
            G[i][0] = a; G[i][1] = b;
        }
        for(int i = 1; i <= N; ++i){
            dap += dfs(i);
            ++visitNum;
        }
        cout << dap << '\n';
    }
    return 0;
}
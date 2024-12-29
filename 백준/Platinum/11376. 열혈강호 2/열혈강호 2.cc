#include<iostream>
#include<vector>
using namespace std;
int C[1010], A[1010], visitNum = 1, dap;
vector<int> G[1010];

int dfs(int v){
    for(auto i : G[v]){
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
    int N, M; cin >> N >> M;
    for(int i = 1, n, v; i <= N; ++i){
        cin >> n;
        while(n--){
            cin >> v;
            G[i].emplace_back(v);
        }
        dap += dfs(i);
        visitNum++;//
        dap += dfs(i);
        visitNum++;
    }
    cout << dap;
    return 0;
}
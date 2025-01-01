#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<string, int> m;
int A[1010], C[1010], visitNum = 1;
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
    int N, M, dap = 0;
    string s;
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        cin >> s;
        m[s] = i;
    }
    for(int i = 1; i <= N; ++i){
        int n; cin >> n;
        for(int j = 1; j <= n; ++j){
            cin >> s;
            G[i].emplace_back(m[s]);
        }
    }
    for(int i = 1; i <= N; ++i){
        dap += dfs(i);
        ++visitNum;
    }
    if(N == dap) cout << "YES";
    else cout << "NO\n" << dap;
    return 0;
}
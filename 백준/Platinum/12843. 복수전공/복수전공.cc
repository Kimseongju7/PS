#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> G[2020];
int C[2020], A[2020], vn = 1;
vector<int> com;

int dfs(int v){
    for(auto i : G[v]){
        if(C[i] == vn) continue;
        C[i]= vn;
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
    map<int, int> c; char ch; int n, v, dap = 0;
    for(int i = 1; i <= N; ++i){
        cin >> n >> ch;
        if(ch == 'c') {
            c[n] = 1;
            com.emplace_back(n);
        }
        else c[n] = 0;
    }
    for(int i = 1; i <= M; ++i){
        cin >> n >> v;
        if(c[n]) G[n].emplace_back(v);
        else G[v].emplace_back(n);
    }
    for(auto i : com){
        dap += dfs(i);
        ++vn;
    }
    cout << N - dap;
    return 0;
}
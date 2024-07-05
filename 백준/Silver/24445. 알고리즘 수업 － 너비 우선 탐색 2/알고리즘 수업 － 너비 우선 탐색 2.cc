#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define endl '\n'
int C[101010], dap[101010], cnt;
vector<int> G[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, r;
    cin >> N >> M >> r;
    for(int i = 0; i < M; ++i){
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for(int i = 1; i <= N; ++i) sort(G[i].rbegin(), G[i].rend());
    queue<int> q;
    q.emplace(r);
    C[r] = 1;
    dap[r] = ++cnt;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto i : G[v]){
            if(C[i]) continue;
            C[i] = 1;
            dap[i] = ++cnt;
            q.emplace(i);
        }
    }
    for(int i = 1; i <= N; ++i) cout << dap[i] << endl;
    return 0;
}
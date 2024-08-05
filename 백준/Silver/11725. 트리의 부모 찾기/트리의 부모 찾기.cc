#include<iostream>
#include<queue>
using namespace std;
#define endl '\n'
int P[101010], C[101010];
vector<int> G[101010];
int N;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i < N; ++i){
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    queue<int> q;
    q.emplace(1); C[1] = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto i : G[v]){
            if(C[i]) continue;
            C[i] = 1;
            q.emplace(i);
            P[i] = v;
        }
    }
    for(int i = 2; i <= N; ++i) cout << P[i] << endl;
    return 0;
}
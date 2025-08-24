#include<iostream>
#include<queue>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    priority_queue<int> q[101];
    int dap[101] = {};
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int t; cin >> t;
            q[i].emplace(t);
        }
    }
    int m = 0;
    for(int t = 0; t < M; t++){
        m = 0;
        for(int i = 0; i < N; i++) m = max(m, q[i].top());
        for(int i = 0; i < N; i++) {
            if(m == q[i].top()) dap[i]++;
            q[i].pop();
        }
    }
    m = 0;
    for(int i = 0; i < N; i++) m = max(m, dap[i]);
    for(int i = 0; i < N; i++) if(m == dap[i]) cout << i + 1 << ' ';
    return 0;
}
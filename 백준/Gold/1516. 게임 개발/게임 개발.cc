#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    queue<pair<int, int> > pq;
    vector<int> v[505];
    int N, dp[505] = {}, m;
    bool ok, val[505] = {};;
    cin >> N;
    for(int i = 1; i <= N; ++i){
        int t; 
        cin >> t; dp[i] = t;
        while(true){
            cin >> t;
            if(t == -1) break;
            v[i].emplace_back(t);
        }
        pq.emplace(v[i].size(), i);
    }
    while(!pq.empty()){
        auto [cnt, i] = pq.front(); pq.pop();
        m = 0;
        ok = true;
        for(int j = 0; j < cnt; ++j){
            int t = v[i][j];
            if(!val[t]) {
                ok = false;
                break;
            }
            m = max(m, dp[t]);
        }
        if(ok) {
            dp[i] += m;
            val[i] = true;
        }
        else pq.emplace(cnt, i);
    }
    for(int i = 1; i <= N; ++i) cout << dp[i] << '\n';
    return 0;
}
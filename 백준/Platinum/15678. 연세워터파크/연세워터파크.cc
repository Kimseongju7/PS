#include<iostream>
#include<deque>
#include<utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long N, D, arr[101010], dp[101010];
    cin >> N >> D; for(int i = 1; i <= N; ++i) cin >> arr[i];
    deque<pair<long long, long long> > q;
    dp[1] = arr[1];
    for(int i = 1; i <= N; ++i){
        if(!q.empty() && i - q.front().second > D) q.pop_front();
        if(!q.empty())dp[i] = max(arr[i], q.front().first + arr[i]);
        while(!q.empty() && q.back().first <= dp[i]) q.pop_back();
        q.emplace_back(dp[i], i);
    }
    long long dap = -1e18;
    for(int i = 1; i <= N; ++i) dap = max(dap, dp[i]);
    cout << dap;
    return 0;
}
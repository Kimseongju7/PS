#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>
#include<utility>

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long N, K; cin >> N >> K;
    long long A[1010101], dap = 1e18, in;
    for(int i = 1; i <= N; ++i) cin >> A[i];
    sort(A + 1, A + N + 1);
    deque<pair<long long, long long> > q;
    dap = A[N - K] - A[1];
    long long t = 1e18;
    for(int i = 1; i < N - K; ++i) {
        while(!q.empty() && q.back().first > A[i + 1] - A[i]) q.pop_back();
        q.emplace_back(A[i + 1] - A[i], i);
    }
    dap += q.front().first;
    for(int i = N - K + 1; i <= N; ++i){
        if(!q.empty() && q.front().second <= i -(N - K)) q.pop_front();
        while(!q.empty() && q.back().first > A[i] - A[i - 1]) q.pop_back(); 
        q.emplace_back(A[i] - A[i - 1], i - 1);
        t = A[i] - A[i - (N - K) + 1];
        dap = min(dap, q.front().first + t);
    }
    cout << dap;
    return 0;
}
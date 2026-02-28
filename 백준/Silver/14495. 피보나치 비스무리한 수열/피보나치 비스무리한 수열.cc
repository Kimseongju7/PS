#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    unsigned long long dp[200] = {};
    dp[1] = dp[2] = dp[3] = 1;
    int N; cin >> N;
    for(int i = 4; i <= N; i++) dp[i] = dp[i - 3] + dp[i - 1];
    cout << dp[N];
    return 0;
}
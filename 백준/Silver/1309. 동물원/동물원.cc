#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, dp[101010] = {};
    cin >> N;
    dp[1] = 3;
    dp[2] = 7;
    for(int i = 3; i <= N; ++i) dp[i] = (dp[i-1] + dp[i - 1] + dp[i - 2]) % 9901;
    cout << dp[N];
    return 0;
}
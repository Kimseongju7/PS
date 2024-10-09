#include<iostream>
using namespace std;
    int dp[1010] = {};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int m = 10007;
    dp[1] = 1;
    dp[2] = dp[1] + 1;
    for(int i = 3; i <= 1000; ++i) dp[i] = (dp[i- 1] + dp[i - 2])% m;
    cout << dp[n];
    return 0;
}
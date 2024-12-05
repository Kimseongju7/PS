#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, dp[101010] = {};
    cin >> N;
    dp[1] = 1; dp[2] = 2; dp[3] = 3; dp[4] = 1;
    for(int i = 5; i <= N; ++i){
        dp[i] = 101010;
        for(int j = 1; j * j <= i; ++j){
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
    cout << dp[N];
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long T, N, dp[101] = {};
    dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2; dp[6] = 3; dp[7] = 4; dp[8] = 5;
    for(int i = 9; i <= 100; ++i){
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    cin >> T;
    while(T--){
        cin >> N;
        cout << dp[N] << '\n';
    }
    return 0;
}
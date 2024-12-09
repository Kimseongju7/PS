#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, dp[50505] = {};
    cin >> N;
    dp[1] = 1;
    for(int i = 2; i <= N; ++i){
        dp[i] = dp[i - 1] + 1;
        for(int j = 1; j * j <= i; ++j){
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[N];
    return 0;
}
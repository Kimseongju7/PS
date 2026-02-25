#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; long long dp[40] = {};
    cin >> N;
    dp[0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < i; j++) dp[i] += dp[j] * dp[i - j - 1];  
    }
    cout << dp[N];
    return 0;
}
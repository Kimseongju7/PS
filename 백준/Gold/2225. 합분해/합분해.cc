#include<iostream>
using namespace std;
#define M 1000000000

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    unsigned long long dp[202][202] = {};
    for(int i = 0; i <= N; ++i) dp[1][i] = 1;
    for(int i = 1; i <= K; ++i){
        for(int j = 0; j <= N; ++j){
            for(int k = 0; k <= j; ++k){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % M;
            }
        }
    }
    cout << dp[K][N];
    return 0;
}
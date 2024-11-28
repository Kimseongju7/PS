#include<iostream>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, l, r, T; cin >> T;
    long long dp[22][22][22] = {};
    dp[1][1][1] = 1;
    dp[2][1][2] = 1;
    dp[2][2][1] = 1;
    for(int i = 3; i <= 20; ++i){
        for(int j = 1; j <= i; ++j){
            for(int k = 1; k <= i; ++k){
                dp[i][j][k] += dp[i - 1][j][k] * (i - 2);
                dp[i][j][k] += dp[i - 1][j - 1][k];
                dp[i][j][k] += dp[i - 1][j][k - 1];
            }
        }
    }
    while (
        T--
    )
    {
        cin >> n >> l >> r;
        cout << dp[n][l][r] << '\n';
        
    }
    
    return 0;
}

// 4 1 2 = 0
// 3 1 2 = -1
// 2 1 2 = -1
// 1 1 2 = 0
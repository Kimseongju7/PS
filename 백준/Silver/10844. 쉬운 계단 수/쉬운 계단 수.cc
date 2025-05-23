#include<iostream>
#define M 1000000000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 
    int N; cin >> N;
    long long dp[101][10] = {}, dap = 0;
    for(int i = 1; i <= 9; ++i) dp[1][i] = 1;
    for(int i = 2; i <= N; ++i){
        for(int j = 0; j <= 9; ++j){
            if(j == 0) dp[i][j] = dp[i - 1][j + 1];
            else if(j == 9) dp[i][j] = dp[i - 1][j - 1] ;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % M;
        }
    }
    for(int i = 0; i <= 9; ++i) dap += dp[N][i];
    cout << dap % M;
    return 0;
}
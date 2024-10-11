#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int dp[15][15] = {};
    for(int i = 1; i <= 15; ++i) dp[0][i] = i;
    for(int i = 1; i <= 14; ++i){
        for(int j = 1; j <= 14; ++j){
            int sum = 0;
            for(int k = 1; k <= j; ++k) sum += dp[i-1][k];
            dp[i][j] = sum;
        }
    }
    int T; cin >> T;

    int N, k; 
    while(T--){
    cin >> N >> k;
    cout << dp[N][k] << '\n';
    }
    return 0;
}
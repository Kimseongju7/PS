#include<iostream>
using namespace std;

int dp[1010][3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    }
    for(int i = 2; i <= N; ++i){
        dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += min(dp[i - 1][1], dp[i - 1][0]);
    }
    cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
    return 0;
}
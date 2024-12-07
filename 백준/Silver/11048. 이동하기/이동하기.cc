#include<iostream>
using namespace std;

int arr[1010][1010], dp[1010][1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j) cin >> arr[i][j];
    }
    dp[1][1] = arr[1][1];
    for(int i = 2; i <= N; ++i) dp[i][1] = dp[i - 1][1] + arr[i][1];
    for(int i = 2; i <= M; ++i) dp[1][i] = dp[1][i - 1] + arr[1][i];
    for(int i = 2; i <= N; ++i){
        for(int j = 2; j <= M; ++j){
            dp[i][j] = max(dp[i][j-1], max(dp[i - 1][j], dp[i - 1][j - 1])) + arr[i][j];
        }
    }
    cout << dp[N][M];
    return 0;   
}
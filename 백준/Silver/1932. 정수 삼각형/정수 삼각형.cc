#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, dp[505][505] = {}, arr[505][505];
    cin >> N;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= i; ++j) cin >> arr[i][j];
    }
    for(int i = 1; i <= N; ++i) dp[N][i] = arr[N][i];
    for(int i = N - 1; i >= 1; --i){
        for(int j = 1; j <= i; ++j){
            dp[i][j] = arr[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    cout << dp[1][1];
    return 0;
}
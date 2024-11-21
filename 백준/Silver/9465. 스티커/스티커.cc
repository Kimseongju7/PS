#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 
    int N, T;
    int arr[101010][2];
    cin >> T;
    while(T--) 
    {
        cin >> N;
        for(int j = 0; j < 2; ++j) for(int i = 1; i <= N; ++i) cin >> arr[i][j];
        long long dp[101010][2] = {};
        dp[1][0] = arr[1][0];
        dp[1][1] = arr[1][1];
        dp[2][0] = dp[1][1] + arr[2][0];
        dp[2][1] = dp[1][0] + arr[2][1];
        for(int i = 3; i <= N; ++i){
            dp[i][0] = arr[i][0] + max(dp[i-1][1], dp[i - 2][1]);
            dp[i][1] = arr[i][1] + max(dp[i-1][0], dp[i-2][0]);
        }
        cout << max(dp[N][0], dp[N][1]) << '\n';
    }
    return 0;
}
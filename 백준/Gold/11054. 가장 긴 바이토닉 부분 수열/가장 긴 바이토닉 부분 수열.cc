#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int dp[1010][2] = {};
    dp[1][0] = 1;
    int N; cin >> N;
    int arr[1010] = {};
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    for(int i = 2; i <= N; ++i){
        for(int j = 1; j < i; ++j){
            if(arr[j] < arr[i]) {
                dp[i][0] = max(dp[j][0] + 1, dp[i][0]);
            }
            else dp[i][0] = max(dp[i][0], 1);
        }
    }
    dp[N][1] = 1;
    for(int i = N - 1; i >= 1; --i){
        for(int j = N; j > i; --j){
            if(arr[i] > arr[j]) {
                dp[i][1] = max(dp[j][1] + 1, dp[i][1]);
            }
            else dp[i][1] = max(dp[i][1], 1);
        }
    }
    int dap = 0;
    for(int i = 1; i <= N; ++i) dap = max(dp[i][1] + dp[i][0], dap);
    cout << dap - 1;
    return 0;
}
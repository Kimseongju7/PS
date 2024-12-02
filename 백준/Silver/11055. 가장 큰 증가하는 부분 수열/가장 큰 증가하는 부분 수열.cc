#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int arr[1010], dp[1010] = {}, N; cin >> N;
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    dp[1] = arr[1];
    for(int i = 2;i <= N; ++i){
        dp[i] = arr[i];
        for(int j = 1; j < i; ++j){
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + arr[i]);
        }
    }
    int dap = 0;
    for(int i = 1; i <= N; ++i) dap = max(dap, dp[i]);
    cout << dap;
    return 0;
}
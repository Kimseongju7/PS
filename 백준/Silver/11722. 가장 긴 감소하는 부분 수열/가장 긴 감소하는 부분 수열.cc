#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; int dp[1010] = {}; int arr[1010];
    cin >> N; for(int i = 1; i <= N; ++i) cin >> arr[i];
    dp[1] = 1;
    for(int i = 2; i <= N; ++i){
        dp[i] = 1;
        for(int j = 1; j < i; ++j){
            if(arr[i] < arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int dap = 0;
    for(int i = 1; i <= N; ++i) dap = max(dp[i], dap);
    cout << dap;
    return 0;
}
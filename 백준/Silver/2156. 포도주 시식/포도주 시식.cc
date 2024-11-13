#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; int dp[10101] ={}, arr[10101] = {};
    cin >> N;
    for(int i = 1; i<= N; ++i) cin >> arr[i];
    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];
    for(int i = 3; i <= N; ++i){
        dp[i] = max(dp[i - 1], max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]));
    }
    cout << dp[N];
    return 0;
}
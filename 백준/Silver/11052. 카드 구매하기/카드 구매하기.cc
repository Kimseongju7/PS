#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    int arr[1010] = {}, dp[1010] = {};
    cin >> N; for(int i = 1; i <= N; ++i) cin >> arr[i];
    dp[1] = arr[1];
    for(int i = 2; i <= N; ++i){
        dp[i] = arr[i];
        for(int j = 0; j < i; ++j) dp[i] = max(dp[i], dp[j] + dp[i - j]);
    }
    cout << dp[N];
    return 0;
}
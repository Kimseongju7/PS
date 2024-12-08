#include<iostream>
using namespace std;
int N, dp[1010101], arr[1010101];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    dp[1] = 0;
    for(int i = 2; i <= N; ++i){
        dp[i] = dp[i - 1] + 1;
        arr[i] = i - 1;
        if(i % 2 == 0) {
            if(dp[i / 2] + 1 < dp[i]){
                dp[i] = dp[i / 2] + 1;
                arr[i] = i / 2;
            }
        }
        if(i % 3 == 0) {
            if(dp[i / 3] + 1 < dp[i]){
                arr[i] = i / 3;
                dp[i] = dp[i / 3] + 1;
            }
        }
    }
    cout << dp[N] << '\n';
    for(int i = N; i != 0; i = arr[i]) cout << i << ' ';
    return 0;
}
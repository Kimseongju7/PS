#include<iostream>
using namespace std;
#define M 15746
long long dp[1010101] = {};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; 
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= N; ++i){
        dp[i] = (dp[i-1] + dp[i - 2]) % M;
    }
    cout << dp[N];
    return 0;
}
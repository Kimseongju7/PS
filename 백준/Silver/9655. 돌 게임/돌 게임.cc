#include<iostream>
using namespace std;
#define SK 0
#define CY 1

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, dp[1010] = {}; cin >> N;
    dp[1] = SK; dp[2] = CY; dp[3] = SK;
    for(int i = 4; i <= N; ++i) dp[i] = !dp[i - 1];
    if(dp[N] == SK) cout << "SK";
    else cout << "CY";
    return 0;
}
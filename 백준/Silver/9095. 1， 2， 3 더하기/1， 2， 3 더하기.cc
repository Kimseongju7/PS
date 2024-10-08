#include<iostream>
using namespace std;
int dp[12];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int n, T;
    cin >> T;
    for(int i = 4; i <= 11; ++i) dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    while(T--){
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;   
}
#include<iostream>
using namespace std;
int dp[20];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i = 1; i <= N; ++i){
        int t, v; cin >> t >> v;
        dp[i] = max(dp[i], dp[i - 1]);
        if(i + t > N + 1);
        else{
            dp[i + t] = max(dp[i + t], dp[i] + v); 
        }
    }
    dp[N + 1] = max(dp[N + 1], dp[N]);
    // cout << endl;
    // for(int i = 1; i <= N; ++i) cout << dp[i] << ' ';
    cout << dp[N + 1];
    return 0;
}
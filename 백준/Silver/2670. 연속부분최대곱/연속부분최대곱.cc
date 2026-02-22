#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    double dp[10101] = {}, dap = 0;
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> dp[i];
    for(int i = 1; i <= N; i++){
        dp[i] = max(dp[i], dp[i - 1] * dp[i]);
        dap = max(dap, dp[i]);
    }

    cout << fixed << setprecision(3) << dap;
    return 0;
}
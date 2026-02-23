#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; int dp[10101] = {};
    cin >> N;
    for(int i = 0; i * i <= N; i++){
        for(int j = 0; j * j + i * i <= N; j++){
            dp[i * i + j * j]++;
        }
    }

    int dap = 0;
    for(int i = 0; i <= N; i++){
        dap += dp[i] * dp[N - i];
    }
    cout << dap;
    return 0;
}
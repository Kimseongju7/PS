#include<iostream>
using namespace std;
#define endl '\n'
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string str;
    int dp[7][7], N; cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = N - 1; j >= 0; j--){
            cin >> str;
            switch (str[0])
            {
                case 'K': dp[i][j] = 13; break;
                case 'Q': dp[i][j] = 12; break;
                case 'J': dp[i][j] = 11; break;
                case 'T': dp[i][j] = 10; break;
                case 'A': dp[i][j] = 1; break;
                default: dp[i][j] = str[0] - '0'; break;
            }
        }
    }


    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int sum = 0;
            if(i - 1 >= 0) sum = dp[i - 1][j];
            if(j - 1 >= 0) sum = max(sum, dp[i][j - 1]);
            dp[i][j] += sum;
        }
    }

    cout << dp[N - 1][N - 1];
    return 0;
}
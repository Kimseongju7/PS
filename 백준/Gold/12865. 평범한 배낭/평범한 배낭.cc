#include<iostream>
using namespace std;

int dp[101010][101];

class item{
    public:
        int w;
        int v;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    item arr[101];
    for(int i = 1; i <= N; ++i){
        int w, v; cin >> w >> v;
        arr[i].w = w; arr[i].v = v;
    }
    for(int i = 1; i <= K; ++i){
        for(int j = 1; j <= N; ++j){
            if(i < arr[j].w) dp[i][j] = dp[i][j - 1];
            else dp[i][j] = max(dp[i][j - 1], dp[i - arr[j].w][j - 1] + arr[j].v);
        }
    }
    cout << dp[K][N];
    return 0;
}
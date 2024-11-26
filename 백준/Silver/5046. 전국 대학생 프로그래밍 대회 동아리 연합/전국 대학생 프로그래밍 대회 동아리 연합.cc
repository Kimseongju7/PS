#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, B, H, W;
    cin >> N >> B >> H >> W;
    int dap = 1010101;
    for(int i = 1; i <= H; ++i){
        int m, n; cin >> m;
        for(int j = 1; j <= W; ++j){
            cin >> n;
            if(N <= n) dap = min(dap, N * m);
        }
    } 
    if(dap <= B) cout << dap;
    else cout << "stay home";
    return 0;
}
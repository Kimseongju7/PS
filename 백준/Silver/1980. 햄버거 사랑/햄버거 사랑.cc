#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, t; cin >> N >> M >> t;
    int dap = 0, coke = 0;
    int n = min(N, M), m = max(N, M);
    dap = t / n; coke = t % n;
    N = t / m;
    int tt, tc, tn; //tt : 햄버거 먹는데 걸리는 시간, tc 콜라 먹는데 걸리는 시간, tn n 햄버거의 개수
    for(int i = 1; i <= N; ++i){
        tn = (t - m * i) / n;
        tc = t - (i * m + tn * n);
        if(tc < coke || (tc == coke && (tn + i) > dap)){
            coke = tc;
            dap = i + tn;
        }
    }
    cout << dap << ' ' << coke;
    return 0;
}
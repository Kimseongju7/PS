#include<iostream>
using namespace std;

double C(int n, int r){
    int x=1, y=1;
    while(r){
        y *= n, x *= r;
        n--, r--;
    }
    return y/x;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, K; cin >> N >> M >> K;
    double dap = 0;
    double t = C(N, M);
    for(int k = K; k <= M; ++k){
        dap += (C(M, k) * 1.0 * C(N - M, M - k));
    }
    dap /= t;
    cout << fixed;
    cout.precision(10);
    cout << dap;
    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long N, A[1010101], B, C, dap, t, tt;
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> A[i];
    cin >> B >> C;
    dap = N;
    for(int i = 1; i <= N; ++i){
        tt = ((A[i] - B) >= 0) ? (A[i] - B) : 0;
        t = ceil(tt / double(C));
        dap += t;
    }
    cout << dap;
    return 0;
}
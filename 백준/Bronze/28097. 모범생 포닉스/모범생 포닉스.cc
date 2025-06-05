#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, t, dap = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> t;
        dap += t;
    }
    dap += ( N - 1) * 8;
    cout << dap / 24 << ' ' << dap % 24;
    return 0;
}
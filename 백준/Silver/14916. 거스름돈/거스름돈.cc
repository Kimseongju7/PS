#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int dap = 0, i;
    while(true){
        if((n - dap * 5) % 2 != 0 && (n - (dap + 1) * 5 < 0)) break;
        dap++;
    }
    if(dap > 0)dap--;
    n = n - dap * 5;
    dap += n / 2;
    n = n - n/2 * 2;
    if(dap == 0 || n != 0) cout << -1;
    else cout << dap;
    return 0;
}
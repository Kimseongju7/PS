#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c; cin >> a >> b >> c;
    int dap1 = a * b, dap2 = a + b * c;
    if(dap1 < dap2) cout << 1;
    else if(dap1 > dap2) cout << 2;
    else cout << 0;
    return 0;
}
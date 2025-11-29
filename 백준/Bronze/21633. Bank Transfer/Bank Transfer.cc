#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    double a, dap = 0;
    cin >> a;
    dap = 25 + a / 100;
    dap = min(2000.0, dap); dap = max(100.0, dap);
    cout << fixed;
    cout.precision(2);
    cout << dap;
    return 0;
}
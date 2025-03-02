#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    double a, b, c, dap = 0; cin >> a >> b >> c;
    dap = max(a * b / c, a / b * c);
    cout << int(dap);
    return 0;
}
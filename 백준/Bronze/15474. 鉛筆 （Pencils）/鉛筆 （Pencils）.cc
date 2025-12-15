#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c; double x, y;
    cin >> a >> x >> b >> y >> c;
    int dap1 = ceil(a / x) * b;
    int dap2 = ceil(a / y) * c;
    cout << min(dap1, dap2);
    return 0;
}
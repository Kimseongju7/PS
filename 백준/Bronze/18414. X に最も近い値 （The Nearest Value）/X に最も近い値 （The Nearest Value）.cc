#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int X, L, R, dap = 0;
    cin >> X >> L >> R;
    if(L <= X && X <= R) cout << X;
    else {
        if(abs(L - X) < abs(R - X)) cout << L;
        else cout << R;
    }
    return 0;
}
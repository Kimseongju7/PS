#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long a, b, x, y, T; cin >> a >> x >> b >> y >> T;
    long long dapa, dapb;
    dapa = (max(T - 30, 0LL) * x) * 21 + a;
    dapb = (max(T - 45, 0LL) * y) * 21 + b;
    
    cout << dapa << ' ' << dapb;
    return 0;
}
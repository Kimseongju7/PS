#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    double a, b, c, d; cin >> a >> b >> c >> d;
    double m0 = a/c + b/d, m1 = c/d + a/b, m2 = d/b + c/a, m3 = b/a + d/c;
    double m = max(max(m0, m1), max(m2, m3));
    if(m == m0) cout << 0;
    else if(m == m1) cout << 1;
    else if(m == m2) cout << 2;
    else cout << 3;
    return 0;
}
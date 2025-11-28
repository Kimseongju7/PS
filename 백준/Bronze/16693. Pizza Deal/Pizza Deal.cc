#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    double a, b, c, d; cin >> a >> b >> c >> d;
    a = a / b;
    c = (c * c * 3.14159265359) / d;
    if(a < c) cout << "Whole pizza";
    else cout << "Slice of pizza";
    return 0;
}
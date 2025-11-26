#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b || b == c || a == c) cout << 'S';
    else if(a + b == c || a + c == b || b + c == a) cout << 'S';
    else cout << 'N';
    return 0;
}
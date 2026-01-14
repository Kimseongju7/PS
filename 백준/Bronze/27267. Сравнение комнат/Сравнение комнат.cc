#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(a * b > c * d) cout << 'M';
    else if(a * b == c * d) cout << 'E';
    else cout << 'P';
    return 0;
}
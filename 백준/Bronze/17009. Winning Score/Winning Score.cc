#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a1, a2, a3, a, b1, b2, b3, b;
    cin >> a3 >> a2 >> a1 >> b3 >> b2 >> b1;
    a = a3 * 3 +  a2 * 2 + a1;
    b = b3 * 3 + b2 * 2 + b1;
    if(a > b) cout << 'A';
    else if (a < b) cout << 'B';
    else cout << 'T';
    return 0;
}
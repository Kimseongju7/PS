#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    a = min(a, b);
    a = a * 100;
    a = a / 2;
    cout << a;
    return 0;
}
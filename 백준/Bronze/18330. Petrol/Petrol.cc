#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    int c = max(a - (b + 60), 0) * 3000;
    a = min(b + 60, a) * 1500;
    cout << a + c;
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d, n; cin >> a >> b >> c >> d >> n;
    cout << max(0, n * 4 - (a + b + c + d));
    return 0;
}
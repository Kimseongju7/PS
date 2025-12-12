#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b; cin >> a >> b;
    cout << max(a + b, a - b) << '\n';
    cout << min(a + b, a - b);
    return 0;
}
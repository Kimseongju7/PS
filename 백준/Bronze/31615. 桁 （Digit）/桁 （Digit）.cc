#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b; cin >> a >> b; a += b;
    cout << to_string(a).length();
    return 0;
}
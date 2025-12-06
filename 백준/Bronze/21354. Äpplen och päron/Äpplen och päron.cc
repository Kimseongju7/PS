#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b; cin >> a >> b;
    a = a * 7; b = b * 13;
    if(a > b) cout << "Axel";
    else if(b > a) cout << "Petra";
    else cout << "lika";
    return 0;
}
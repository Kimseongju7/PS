#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a = 100, b = 100, x, y, T; cin >> T;
    while(T--){
        cin >> x >> y;
        if(x > y) b -= x;
        else if(y > x) a -= y;
    }
    cout << a << '\n' << b;
    return 0;
}
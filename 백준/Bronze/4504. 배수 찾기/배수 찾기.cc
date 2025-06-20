#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n;
    while(true){
        cin >> x;
        if(!x) break;
        if(x % n == 0) cout << x << " is a multiple of ";
        else cout << x << " is NOT a multiple of ";
        cout << n << ".\n";
    }
    return 0;
}
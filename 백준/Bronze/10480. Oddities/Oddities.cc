#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, x; cin >> N;
    while(N--){
        cin >> x;
        if(x & 1) cout << x << " is odd\n";
        else cout << x << " is even\n";
    }
    return 0;
}
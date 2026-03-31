#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, sum = 0, t; cin >> T;
    while(T--){
        cin >> t;
        sum += t;
    }
    cout << sum;
    return 0;
}
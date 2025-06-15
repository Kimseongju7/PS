#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int S, T, D;
    cin >> S >> T >> D;
    cout << (D/(S*2))*T;
    
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int A, B; cin >> A >> B;
    A = (A + B) % 12;
    if(A == 0) cout << 12;
    else cout << A;
    return 0;   
}
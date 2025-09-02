#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n0, n1, n2, n3, n4;
    for(int i = 1; ; i++){
        cin >> n0;
        if(!n0) break;
        cout << i << ". ";
        n1 = 3 * n0; 
        cout << ((n1 & 1) ? "odd " : "even ");
        n2 = (n1 & 1) ? (n1 + 1)/2 : n1 / 2;
        n3 = 3 * n2;
        n4 = n3 / 9;
        cout << n4 << '\n';
    }
    return 0;   
}
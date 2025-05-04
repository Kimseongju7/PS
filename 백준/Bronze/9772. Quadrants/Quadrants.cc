#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    double a, b;
    while(true){
        cin >> a >> b;
        if(a > 0 && b > 0) cout << "Q1";
        else if(a < 0 && b > 0) cout << "Q2";
        else if(a < 0 && b < 0) cout << "Q3";
        else if(a > 0 && b < 0) cout << "Q4";
        else cout << "AXIS";
        cout << '\n';
        if(a == 0 && b == 0) break;
    }
}
#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, a, b; cin >> T;
    while(T--){
        cin >> a >> b;
        if(a < b){
            int t = a;
            a = b;
            b = t;
        }
        cout << lcm(a, b) << ' ' << gcd(a, b) << '\n';
    }
    return 0;
}
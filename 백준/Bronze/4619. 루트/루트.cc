#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long a, b, m, n;
    while(true){
        m = 2000000;
        cin >> b >> n;
        if(n == 0 && b == 0) break;
        
        for(long long i = 0; pow(i, n) < 2000000; i++){
            long long t = pow(i, n);
            if(abs(b - t) < m){
                m = abs(b - t);
                a = i;
            }
        }
        cout << a << '\n';
    }
    return 0;
}
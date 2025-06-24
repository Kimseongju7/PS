#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    unsigned long long T, a, b, c, d, tmp;
    cin >> T;

    while(T--){
        cin >> a >> b >> c >> d;
        if(a >= b && a >= c){
            tmp = min(d, a - max(b, c));
            a -= tmp;
            d -= tmp;
        }
        else if(b >= a && b >= c){
            tmp = min(d, b - max(a, c));
            b -= tmp;
            d -= tmp;
        }
        else{
            tmp = min(d, c - max(b, a));
            c -= tmp;
            d -= tmp;
        }
        // cout << "1 : " << a << ' ' << b << ' ' << c << ' ' << d << endl;
        if(d == 0) {
            cout << a * b * c << '\n';
            
            continue;
        }
        
        if(a <= b && a <= c){
            tmp = min(d, (b - a) * 2);
            d -= tmp;
            b -= tmp % 2 == 0 ? tmp / 2ULL : tmp / 2ULL + 1ULL;
            c -= tmp/2ULL;
        }
        else if(b <= a && b <= c){
            tmp = min(d, (a - b) * 2);
            d -= tmp;
            a -= tmp % 2 == 0 ? tmp / 2ULL : tmp / 2ULL + 1ULL;
            c -= tmp/2ULL;
        }
        else{
            tmp = min(d, (b - c) * 2);
            d -= tmp;
            b -= tmp % 2 == 0 ? tmp / 2ULL : tmp / 2ULL + 1ULL;
            a -= tmp/2ULL;
        }
        // cout << "2 : " << a << ' ' << b << ' ' << c << ' ' << d << endl;
        if(d == 0) {
            cout << a * b * c << '\n';
            continue;;
        }

        tmp = d / 3ULL;
        a -= tmp;
        b -= tmp;
        c -= tmp;
        if(d % 3 == 2){
            a--;
            b--;
        }
        else if(d % 3 == 1){
            a--;
        }
        
        // cout << "3 : " << a << ' ' << b << ' ' << c << ' ' << d << endl;
        cout << a * b * c << '\n';
    }
    return 0;
}
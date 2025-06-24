#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long T, a, b, c, d, tmp;
    cin >> T;

    while(T--){
        cin >> a >> b >> c >> d;
        while(d > 0){
            if(a >= b && a >= c){
                tmp = min(d, a - max(b, c) + 1);
                a -= tmp;
                d -= tmp;
            }
            else if(b >= a && b >= c){
                tmp = min(d, b - max(a, c) + 1);
                b -= tmp;
                d -= tmp;
            }
            else{
                tmp = min(d, c - max(b, a) + 1);
                c -= tmp;
                d -= tmp;
            }
        }
        cout << a * b * c << '\n';
    }
    return 0;
}
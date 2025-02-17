#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        int x1, y1, r1, x2, y2, r2, d;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int x = x2 - x1, y = y2 - y1;
        d = x * x + y * y;
        int rr = r1 + r2, rrr = r1 - r2;
        rr = rr * rr; rrr = rrr * rrr;
        if(d == 0){
            if(rrr == 0) cout << -1;
            else cout << 0;
        }
        else if(x1 == x2 && y1 == y2) cout << 0;
        else if(d == rr || d == rrr) cout << 1;
        else if(d < rr && d > rrr ) cout << 2;
        else cout << 0;
        cout << '\n';
    }
    return 0;
}
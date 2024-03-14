#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout << setprecision(1);
    double min, res;
    cin >> min;
    if(min < 30) res = min / 2;
    else {
        res = 15;
        min -= 30;
        res += min * 1.5;
    }
    cout << res << '\n';
    return 0;
}
#include <iostream>
#include<cstdlib>
#define endl '\n'
using namespace std;

int main(){
    using ull = unsigned long long;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ull num = 1, n, cnt = 1;
    while(cin >> n) {
        num = 1;
        cnt = 1;
        while(num % n != 0){
            num = (num * 10) % n + 1 % n; // (11 * 10 + 1) = 111
            //111 % n 과 (11*10) % n + 1 % n의 결과값은 같음s
            ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}
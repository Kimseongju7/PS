#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, min6, min, res = 0, six, one;
    min = min6 = 1001;
    cin >> N >> M;
    while(M--){
        cin >> six >> one;
        if(six < min6) min6 = six;
        if(one < min) min = one;
    }
    while(N > 0){
        if(N >= 6){
            if(min6 <= min * 6){
                res += min6 * (N / 6);
                N %= 6;
            }
            else {
                res += min * N;
                N = 0;
            }
        }
        else{
            if(min6 <= (min * N)){
                res += min6;
            }
            else {
                res += min * N;
            }
            N = 0;
        }
    }
    cout << res << endl;
    return 0;
}
#include <iostream>
using namespace std;
#define endl '\n'
using ULL = unsigned long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ULL T, N;
    bool prime;
    cin >> T;
    while(T--){
        cin >> N;
        if(N <= 2) {
            cout << 2 << endl;
            continue;
        }
        for(ULL i = N; ; ++i){
            prime = true;
            for(ULL j = 2; j * j <= i; ++j){
                if(i % j == 0) {
                    prime = false;
                    break;
                }
            }
            if(prime){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
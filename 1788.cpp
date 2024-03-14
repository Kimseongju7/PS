#include <iostream>
using namespace std;
#define endl '\n'
#define M 1000000000

int main(){
    using ULL = unsigned long long;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, n;
    ULL f0, f1, fn;
    cin >> N;
    n = N >= 0 ? N : -N;
    f0 = 0;
    f1 = 1;
    if(n == 0) cout << 0 << endl << 0;
    else if(n == 1) cout << 1 << endl << 1;
    else{
        for(int i = 2; i <= n; ++i){
            fn = (f0 + f1) % M;
            f0 = f1;
            f1 = fn;
        }
        if(N < 0 && n % 2 == 0) cout << -1 << endl;
        else cout << 1 << endl;
        cout << fn; 
    }
    return 0;
}
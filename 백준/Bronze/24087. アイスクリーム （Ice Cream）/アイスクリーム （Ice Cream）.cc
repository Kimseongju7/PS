#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
   int S, A, B; cin >> S >> A >> B;
   int dap = 250;
    S = S - A;
    if(S <= 0) cout << dap;
    else {
        dap += ceil(S / (double)B) * 100;
        cout << dap;
    }
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, dap = 0, l, t;
    cin >> N;
    while(N--){
        cin >> l >> t;
        if(l == 136) dap += 1000;
        else if(l == 142) dap += 5000;
        else if(l == 148) dap += 10000;
        else dap += 50000;
    }
    cout << dap;
    return 0;
}
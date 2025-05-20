#include<iostream>
using namespace std;
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, dap, a, b;

    while(true){
        cin >> N; if(!N) break;
        dap = 1;
        while(N--){
            cin >> a >> b;
            dap = dap * a - b;
        }
        cout << dap << endl;
    }
    return 0;
}
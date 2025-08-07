#include<iostream>
using namespace std;

int main(){
    int dap = 0, T, N, M;
    cin >> T;
    while(T--){
        cin >> N >> M;
        dap = 0;
        for(int a = 1; a < N; a++) for(int b = a + 1; b < N; b++){
            int t = a * a + b * b + M, t2 = a * b;
            if(t % t2 == 0) ++dap;
        }
        cout << dap << '\n';
    }
    return 0;
}
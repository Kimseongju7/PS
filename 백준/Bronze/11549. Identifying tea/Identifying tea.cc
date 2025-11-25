#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, a, dap = 0;
    cin >> N;
    for(int i = 0; i < 5; i++){
        cin >> a;
        dap += (N == a);
    }
    cout << dap;
    return 0;
}
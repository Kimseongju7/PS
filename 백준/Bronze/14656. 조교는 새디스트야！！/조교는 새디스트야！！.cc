#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, n, dap = 0;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> n;
        dap += (n != i);
    }
    cout << dap;
    return 0;
}
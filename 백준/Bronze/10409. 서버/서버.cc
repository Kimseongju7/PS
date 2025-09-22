#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, T, n, dap = 0, sum = 0;
    cin >> N >> T;
    for(int i = 0; i < N; i++){
        cin >> n; sum += n;
        if(sum > T) break;
        dap++;
    }
    cout << dap;
    return 0;
}
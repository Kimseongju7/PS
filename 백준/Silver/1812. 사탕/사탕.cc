#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, A[1010], dap[1010], t = 0; cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
        if(i & 1) t += A[i];
        else t -= A[i];
    }
    dap[1] = t / 2;
    cout << dap[1] << endl;
    for(int i = 2; i <= N; ++i){
        dap[i] = A[i - 1] - dap[i - 1];
        cout << dap[i] << endl;
    }


    return 0;
}

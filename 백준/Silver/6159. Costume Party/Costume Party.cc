#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, S, dap = 0;
    int A[20202] = {};
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(A[i] + A[j] <= S) ++dap;
        }
    }
    cout << dap;
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, L; int A[55] = {};
    int x, dap = 0; cin >> N >> M >> L;
    x = 0;
    while(true){
        A[x]++;
        if(A[x] == M) break;
        ++dap;
        if(A[x] & 1) x = x + L;
        else{
            x = x + (N - L);
        }
        x = x % N;
    }
    cout << dap;
    return 0;
}
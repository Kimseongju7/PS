#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int A[1010] = {}, C[1010] = {}, N, n;
    cin >> N >> n;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    while(true){
        C[n] = 1;
        if(C[A[n]]){
            cout << n;
            break;
        }
        n = A[n];
    }
    return 0;
}
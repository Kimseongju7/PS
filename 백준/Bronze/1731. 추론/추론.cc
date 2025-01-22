#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, A[55];
    cin >> N; for(int i = 1; i <= N; ++i) cin >> A[i];
    if(A[2] - A[1] == A[3] - A[2]){
        cout << A[N] + (A[2] - A[1]);
    }
    else cout << A[N] * (A[2] / A[1]);
    return 0;
}
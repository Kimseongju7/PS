#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, N, A[22] = {};
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; ++i) cin >> A[i];
        sort(A, A + N);
        cout << (A[N - 1] - A[0]) * 2 << '\n';
    }
    return 0;
}
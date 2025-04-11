#include<iostream>
#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int A[5050] = {};
    int T, N[1010] = {}, K, i;
    bool b = true;
    cin >> T;
    for(int i = 1; i <= T; ++i) cin >> N[i];
    cin >> K;
    for(int i = 1; i < 5050; ++i) A[i] = K + 1;
    for(i = 1; b; ++i){
        b = false;
        for(int j = 1; j <= T; ++j){
            if(i - N[j] < 0) continue;
            if(A[i - N[j]] != (K + 1) && A[i - N[j]] + 1 < A[i] && A[i - N[j]] + 1 <= K){
                b = true;
                A[i] = A[i - N[j]] + 1;
            }
        }
    }
    if(i & 1) cout << "holsoon win at " << i - 1;
    else cout << "jjaksoon win at " << i - 1;
    return 0;
}
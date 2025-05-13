#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int A[55] = {}; 
    for(int i = 0; i < N; i++) cin >> A[i];
    int m = 0, cnt = 0;
    for(int i = 0; i < N; i++){
        if(A[i] > m){
            cnt++;
            m = A[i];
        }
    }
    cout << cnt << '\n';
    m = 0, cnt = 0;
    for(int i = 0; i < N; i++){
        if(A[N - i - 1] > m){
            cnt++;
            m = A[N - i - 1];
        }
    }
    cout << cnt;
    return 0;
} 
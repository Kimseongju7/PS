#include<iostream>
using namespace std;
char A[10101];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    int cnt = 0;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++){
        char t; cin >> t;
        cnt += (A[i] == t);
    }
    cout << cnt;
    return 0;
}
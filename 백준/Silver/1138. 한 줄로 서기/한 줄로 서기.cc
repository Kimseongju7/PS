#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, A[10] = {}, t, cnt;
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> t;
        cnt = 0;
        for(int j = 0; j < N; ++j){
            if(A[j] == 0 && cnt == t){
                A[j] = i;
                break;
            }
            if(A[j] == 0) ++cnt;
        }
    }
    for(int i = 0; i < N; ++i) cout << A[i] << ' ';
    return 0;
}
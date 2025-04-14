#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, P, M, t;
    int A[55] = {};
    bool S[55][1010] = {}; //0은 +, 1은 -
    cin >> N >> P >> M;
    S[0][P] = true;
    for(int i = 1; i <= N; ++i) cin >> A[i];
    for(int i = 1; i <= N; ++i){
       for(int j = 0; j <= M; ++j){
            if(S[i - 1][j]){
                if(j + A[i] <= M) S[i][j + A[i]] = true;
                if(j - A[i] >= 0) S[i][j - A[i]] = true;
            }
       }
    }
    for(int i = M; i >= 0; --i) if(S[N][i]) {
        cout << i;
        return 0;
    }
    cout << -1;
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; char A[1010][1010]; char D[1010][1010] = {};
    cin >> N;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) cin >> A[i][j];
    int cnt = 0;
    for(int i = 1;i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if('1' <= A[i][j] && A[i][j] <= '9') {
                D[i][j] = '*';
            }
            else {
                cnt = 0;
                for(int l = i - 1; l <= i + 1; ++l){
                    for(int k = j - 1; k <= j + 1; ++k){
                        if(l < 1 || l > N || k < 1 || k > N || A[l][k] == '.') continue;
                        cnt += A[l][k] - '0';
                    }
                }
                if(cnt >= 10) D[i][j] = 'M';
                else D[i][j] = cnt + '0';
            }
        }
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) cout << D[i][j];
        cout << '\n';
    }
    return 0;
}
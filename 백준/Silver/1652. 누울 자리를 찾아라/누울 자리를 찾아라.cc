#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    char A[101][101];
    int N;
    cin >> N;
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) cin >> A[i][j];
    int dapx = 0, dapy = 0;
    int t;
    for(int i = 1; i <= N; ++i) {
        t = 0;
        for(int j = 1; j <= N; ++j) {
            if(A[i][j] == 'X'){
                if(j - t - 1 >= 2) ++dapx;
                t = j;
            }
            else if(j == N){
                if(j - t >= 2) ++dapx;
            }
        }
    }
    for(int i = 1; i <= N; ++i) {
        t = 0;
        for(int j = 1; j <= N; ++j) {
            if(A[j][i] == 'X'){
                if(j - t - 1 >= 2) ++dapy;
                t = j;
                
            }
            else if(j == N){
                if(j - t >= 2) ++dapy;
            }
        }
    }
    cout << dapx << ' ' << dapy;
    return 0;
}
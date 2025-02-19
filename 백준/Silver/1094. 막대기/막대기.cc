#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int X, N = 0 | 64, N2 = 0, T = 3; cin >> X;
    while((N + N2) != X){
        int t = 0;
        for(int i = 1; i <= 64; i *= 2){
            if(N & i) {
                // cout << i << ' ';
                t = i >> 1;
                // cout << "t : " << t;
                //2개 있는 경우
                if(N2 & i){
                    N2 ^= i;
                    N |= t;
                }
                //1개만 있는 경우
                else{
                    N ^= i;
                    N |= t;
                }
                break;
            }
        }
        if(N + N2 < X){
            N2 |= t;
        }
        // cout << endl << N << endl;
    }
    //개수 구하기
    int cnt = 0;
    for(int i = 1; i <= 64; i *= 2){
        if(N & i) ++cnt;
        if(N2 & i) ++cnt;
    }
    cout << cnt;
    return 0;
}
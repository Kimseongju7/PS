#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    char A[10][10] = {}, c;
    int N, i = 1, j = 1, ni = 1, nj = 1, dr;
    cin >> N;
    while(true){
        cin >> c;
        if(cin.eof()) break;
        ni = i; nj = j;
        if(c == 'U') ni = i - 1, dr = 1;
        else if(c == 'D') ni = i + 1, dr = 1;
        else if(c == 'R') nj = j + 1, dr = 0;
        else if(c == 'L') nj = j - 1, dr = 0;
        if(ni < 1 || ni > N || nj < 1 || nj > N) continue;
        if(dr){
            if(A[i][j] == '-' || A[i][j] == '+') A[i][j] = '+';
            else A[i][j] = '|';
            if(A[ni][nj] == '-' || A[ni][nj] == '+') A[ni][nj] = '+';
            else A[ni][nj] = '|';
        }
        else {
            if(A[i][j] == '|' || A[i][j] == '+') A[i][j] = '+';
            else A[i][j] = '-';
            if(A[ni][nj] == '|' || A[ni][nj] == '+') A[ni][nj] = '+';
            else A[ni][nj] = '-';
        }
        i = ni; j = nj;
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j) {
            if(A[i][j]) cout << A[i][j];
            else cout << '.';
        }
        cout << endl;
    }
    return 0;
}
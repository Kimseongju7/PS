#include<iostream>
using namespace std;
int C[25][25], A[25][25];

int check2(int r, int c){
    int sum = 0, ret = 0;
    C[r][c] = 1;
    for(int i = 0; i < 5; i++) sum += C[i][c];
    if(sum == 5) ret++; sum = 0;
    for(int j = 0; j < 5; j++) sum += C[r][j];
    if(sum == 5) ret++; sum = 0;
    if(r + c == 4){
       for(int i = 0; i < 5; i++){
         sum += C[0 + i][4 - i];
       }
       if(sum == 5) ret++; sum = 0;
    }
    if(r == c){
        for(int i = 0; i < 5; i++) sum += C[i][i];
        if(sum == 5) ret++;
    }
    return ret;
}

int check(int n){  
    for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++){
        if(n == A[i][j]) return check2(i, j);
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int bingo = 0, t;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) cin >> A[i][j];
    }
    for(int k = 1; k <= 25; k++){
        cin >> t;
        bingo += check(t);
        if(bingo >= 3) {
            // cout << "dap : ";
            cout << k << '\n';
            return 0;
        }
    }

    return 0;
}
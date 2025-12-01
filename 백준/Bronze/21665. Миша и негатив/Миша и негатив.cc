#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r, c, dap = 0;
    char A[101][101], ch;
    cin >> r >> c;
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> A[i][j];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> ch;
            dap += (ch ==  A[i][j]);
        }
    }
    cout << dap;
    return 0;
}
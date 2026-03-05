#include<iostream>
using namespace std;

char dap[7000][7000];

void solve(int r, int c, int N, bool blank){
    // if(N == 3 && !blank){
    //     dap[r][c] = dap[r][c + 1] = dap[r][c + 2] = dap[r + 1][c] = dap[r + 1][c + 2] = '*';
    //     dap[r + 2][c] = dap[r + 2][c + 1] = dap[r + 2][c + 2] = '*';
    //     dap[r + 1][c + 1] = ' ';
    //     return;
    // }
    // else if(N == 3 && )

    if(N == 1){
        if(blank) dap[r][c] = ' ';
        else dap[r][c] = '*';
        return;
    }

    int cnt = 0;
    bool b = false; // black가 true로 들어온 것들은 다 true로 해주어야 함

    for(int i = r; i < r + N; i += N / 3){
        for(int j = c; j < c + N; j += N / 3) {
            cnt++;
            if(cnt == 5)  b = true;
            solve(i, j, N / 3, b | blank);
            b = false;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    // cout << "Sorlve Start\n";
    solve(0, 0, N, false);
    // cout << "Solved\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << dap[i][j];
        cout << '\n';
    }
    return 0;   
}
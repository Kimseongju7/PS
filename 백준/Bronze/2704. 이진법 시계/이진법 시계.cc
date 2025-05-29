#include<iostream>
#include<string>
using namespace std;

int main(){
    cin.tie()->sync_with_stdio(0);
    int T; cin >> T;
    int dap[3][6] = {};
    char c;
    int time[3];
    while(T--){
        cin >> time[0] >> c >> time[1] >> c >> time[2];
        for(int k = 0; k < 3; k++){
            for(int i = 5; i >= 0; i--){
                if(time[k] >= 1 << i) {
                    dap[k][5 - i] = 1;
                    time[k] -= 1 << i;
                }
                else dap[k][5 - i] = 0;
            }
        }
        for(int i = 0; i < 6; i++) for(int j = 0; j < 3; j++) cout << dap[j][i];
        cout << ' ';
        for(int i = 0; i < 3; i++) {for(int j = 0; j < 6; j++) cout << dap[i][j];}
        cout << '\n';
        // memset(dap, 0, sizeof(dap));
    }
    return 0;
}
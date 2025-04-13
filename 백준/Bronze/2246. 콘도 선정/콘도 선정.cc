#include<iostream>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int A[10101][2], dap = 0;
    bool b;
    int N; cin >> N;
    for(int i = 1; i <= N; ++i) cin >> A[i][0] >> A[i][1];
    for(int i =1 ; i <= N; ++i){
        b = true;
        for(int j = 1; j <= N; ++j){
            if(i == j) continue;
            if((A[i][0] > A[j][0] && A[i][1] >= A[j][1]) || (A[i][1] > A[j][1] && A[i][0] >= A[j][0])) {
                b = false;
                break;
            }

        }
        dap += b;
    }
    cout << dap;
    return 0;
}
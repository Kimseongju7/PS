#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    int A[101][101] = {};
    int x1, y1, x2, y2;
    cin >> N >> M;
    while(N--){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i++){
            for(int j = y1; j <= y2; j++) A[i][j]++;
        }
    }
    int dap = 0;
    for(int i = 1; i <= 100; i++) for(int j = 1; j <= 100; j++) if(A[i][j] > M) ++dap;
    cout << dap;
    return 0;
}
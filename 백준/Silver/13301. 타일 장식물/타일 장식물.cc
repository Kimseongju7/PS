#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    long long D[88][2] = {};
    D[1][0] = 1, D[1][1] = 1;
    D[2][0] = 1, D[2][1] = 2;
    cin >> N;
    for(int i = 3; i <= N; i++){
        if(i % 2 == 0){
            D[i][0] = D[i - 1][0];
            D[i][1] = D[i][0] + D[i - 1][1];
        }
        else{
            D[i][1] = D[i - 1][1]; 
            D[i][0] = D[i][1] + D[i - 1][0];
        }
    }
    cout << D[N][0] * 2 +  D[N][1] * 2;
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, d;
    double D[101][2] = {}, p[4] = {};
    cin >> N >> d;
    if(d) D[0][1] = 1;
    else D[0][0] = 1;
    for(int i = 0; i < 4; i++) cin >> p[i]; // OO, OX, XO, XX
    for(int i = 1; i <= N; i++){
        D[i][0] = D[i - 1][0] * p[0] + D[i - 1][1] * p[2];
        D[i][1] = D[i - 1][0] * p[1] + D[i - 1][1] * p[3];
    }
    cout << (int)(D[N][0] * 1000) << '\n' << (int)(D[N][1] * 1000);
    return 0;
}
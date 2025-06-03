#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, D = 0, P = 0;
    char c;
    cin >> N;
    while(N--){
        cin >> c;
        if(c == 'D') D++;
        else P++;
        if(abs(D - P) >= 2) break;
    }
    cout << D << ":" << P;
    return 0;
}
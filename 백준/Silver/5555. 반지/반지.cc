#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; string s, S;
    cin >> s;
    cin >> N;
    int dap = 0;
    while(N--){
        cin >> S;
        S += S;
        if(S.find(s) !=  string::npos) ++dap;
    }
    cout << dap;
    return 0;
}
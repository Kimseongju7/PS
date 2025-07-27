#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a = 0, b = 0, c = 0, N, dap = 0;
    string s;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        if(s[0] == '3') ++c;
        else if(s[2] == '4') ++a;
        else ++b;
    }

    while(a >= 1 && c >= 1){
        --a; --c; ++dap;
    }

    while(b >= 2){
        b -= 2; ++dap;
    }

    while(b >= 1 && a >= 2){
        a -= 2; b--; ++dap;
    }

    while(a >= 4){
        a -= 4; ++dap;
    }

    while(c >= 1){
        --c; ++dap;
    }

    while(b >= 1 && a >= 1){
        --a; --b; ++dap;
    }

    while(a >= 3){
        a -= 3; ++dap;
    }

    while(b >= 1){
        --b; ++dap;
    }

    while(a >= 2){
        a -= 2; ++dap;
    }

    while(a >= 1){
        --a; ++dap;
    }

    cout << dap;
    return 0;
}
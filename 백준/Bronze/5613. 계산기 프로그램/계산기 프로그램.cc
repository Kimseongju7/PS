#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int dap, n;
    char op;
    cin >> dap;
    while(true){
        cin >> op;
        if(op == '=') {
            cout << dap;
            break;
        }
        cin >> n;
        if(op == '+') dap += n;
        else if(op == '-') dap -= n;
        else if(op == '/') dap /= n;
        else if(op == '*') dap *= n;
    }
    return 0;
} 
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, t, dap = 0; char c;
    cin >> N;
    while(N--){
        cin >> c >> c>> t;
        if(t <= 90) ++dap;
    }
    cout << dap;
    return 0;
}
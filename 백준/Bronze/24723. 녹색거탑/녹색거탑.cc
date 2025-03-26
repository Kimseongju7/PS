#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long dap = 1;
    int N;
    cin >> N;
    for(int i = 1; i <= N; ++i) dap *= 2;
    cout << dap;
    return 0;
}
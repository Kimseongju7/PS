#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a, b; cin >> a >> b;
    cout << a  *(b - 1) + 1;
    return 0;
}
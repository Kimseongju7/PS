#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    if(N & 1) cout << "CY";
    else cout << "SK";
    return 0;
}
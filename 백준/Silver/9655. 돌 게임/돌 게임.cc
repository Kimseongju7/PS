#include<iostream>
using namespace std;
#define SK 0
#define CY 1

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    if(N % 2) cout << "SK";
    else cout << "CY";
    return 0;
}
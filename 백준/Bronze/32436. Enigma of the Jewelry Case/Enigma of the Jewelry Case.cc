#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, a[55][55];
    cin >> N;
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) cin >> a[i][j];
    if(a[0][0] < a[0][1] &&  a[0][0] < a[1][0]) cout << 0;
    else if(a[0][0] > a[0][1] && a[0][0] < a[1][0]) cout << 1;
    else if(a[0][0] > a[0][1] && a[0][0] > a[1][0]) cout << 2;
    else cout << 3; 
    return 0; 
}
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K;
    cout << N - abs(M - K);
    return 0;
}
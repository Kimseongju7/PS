#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long S, N; cin >> S;
    for(N = 1; S - N >= 0; N++) S -= N;
    cout << N - 1;
    return 0;
}
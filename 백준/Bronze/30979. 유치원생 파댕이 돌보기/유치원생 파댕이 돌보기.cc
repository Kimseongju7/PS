#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, N, sum = 0, t; cin >> T >> N;
    while(N--){
        cin >> t; sum += t;
    }
    cout << (sum >= T ? "Padaeng_i Happy" : "Padaeng_i Cry");
    return 0;
}
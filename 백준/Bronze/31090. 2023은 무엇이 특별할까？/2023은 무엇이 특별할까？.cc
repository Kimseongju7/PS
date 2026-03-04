#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, N; cin >> T;
    while(T--){
        cin >> N;
        if((N + 1) % (N % 100) == 0) cout << "Good";
        else cout << "Bye";
        cout << '\n';
    }
    return 0;
}
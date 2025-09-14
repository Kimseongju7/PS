#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for(int i = 1; i <= N + 2; i++){
        if(i == 1 || i == N + 2) for(int j = 0; j < N + 2; j++) cout << '@';
        else {
            cout << "@"; for(int j = 0; j < N; j++) cout << ' '; cout << '@';
        }
        cout << '\n';
    }
    return 0;
}
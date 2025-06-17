#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, N, a, b;
    cin >> T;
    while(T--){
        cin >> N;
        while(N--){
            cin >> a >> b;
            cout << a + b << ' ' << a * b << '\n';
        }
    }
    return 0;
}
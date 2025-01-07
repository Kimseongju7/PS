#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, T;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                if(i == 1 || i == N || j == 1 || j == N) cout << '#';
                else cout << 'J';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;   
}
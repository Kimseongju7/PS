#include<iostream>
#include<cmath>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    string s;
    while(T--){
        cin >> s;
        int N = sqrt(s.length());
        for(int i = 0; i < N; ++i){
            for(int j = 1; j <= N; ++j){
                cout << s[N * j - i - 1];
            }
        }
        cout << endl;
    }
    return 0;
}
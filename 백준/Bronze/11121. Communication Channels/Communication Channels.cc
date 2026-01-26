#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; string s1, s2; cin >> T;
    while(T--){
        cin >> s1 >> s2;
        cout << (s1 == s2 ? "OK" : "ERROR") << '\n';
    }
    return 0;
}
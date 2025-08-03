#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int SUM = 0, T, C[26] = {};
    string s;
    cin >> T;
    while(T--){
        cin >> s;
        for(int i = 0; i < 26; i++) C[i] = 0;
        SUM = 0;
        for(int i = 0; i < s.length(); i++) C[s[i] - 'A'] = 1;
        for(int i = 0; i < 26; i++) if(!C[i]) SUM += 'A' + i;
        cout << SUM << '\n';
    }
    return 0;
}
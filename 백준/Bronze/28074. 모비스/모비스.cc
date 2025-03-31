#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    bool m = 0, o = 0, b = 0, i = 0, s = 0;
    string str;
    cin >> str;
    for(int j = 0; j < str.length(); ++j){
        if(str[j] == 'M') m = true;
        if(str[j] == 'O') o = true;
        if(str[j] == 'B') b = true;
        if(str[j] == 'I') i = true;
        if(str[j] == 'S') s = true;
    }
    if(m && o && b && i && s) cout << "YES";
    else cout << "NO";
    return 0;
}
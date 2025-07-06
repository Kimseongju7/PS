#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    string s;
    int len;
    while(T--){
        cin >> s; len = s.length() / 2;
        if(s[len] == s[len - 1]) cout << "Do-it\n";
        else cout << "Do-it-Not\n";
    }
    return 0;
}
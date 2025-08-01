#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    while(true){
        getline(cin, s);
        if(s == "***") break;
        for(int i = s.length() - 1; i >= 0; i--) cout << s[i];
        cout << '\n';
    }
    return 0;
}
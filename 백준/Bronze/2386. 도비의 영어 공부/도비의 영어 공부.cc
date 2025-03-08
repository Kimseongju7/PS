#include<iostream>
#include<cctype>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s; char c; int cnt;
    while(true){
        cnt = 0;
        cin >> c;
        if(c == '#') break;
        getline(cin, s);
        for(int i = 0; i < s.length(); ++i){
            if(c == tolower(s[i])) ++cnt;
        }
        cout << c <<' ' << cnt << '\n';
    }
    return 0;
}
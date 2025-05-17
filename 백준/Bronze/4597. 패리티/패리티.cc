#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    int len, cnt;
    while(true){
        cnt = 0;
        cin >> s;
        if(s == "#") break;
        len = s.length();
        for(int i = 0; i < len - 1; i++){
            if(s[i] == '1') ++cnt;
        }
        if(s[len - 1] == 'e'){
            if(cnt & 1) s[len - 1] = '1';
            else s[len - 1] = '0';
        }
        else{
            if(cnt & 1) s[len - 1] = '0';
            else s[len - 1] = '1';
        }
        cout << s << '\n';
    }
    return 0;
}
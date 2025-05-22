#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    getline(cin, s);
    int len = s.length();
    for(int i = 0; i < len; i++){
        cout << s[i];
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            i += 2;
        }
    }
    return 0;
}
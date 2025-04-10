#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s; int n;
    bool b = false;
    cin >> s;
    n = s[0] - '0';
    if(n == 0) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < s.length(); ++i){
        n = s[i] - '0';        
        if(n >= 4) cout << 1, n -=4, b = true;
        else if(b) cout << 0;
        if(n >= 2) cout << 1, n -=2, b = true;
        else if(b)cout << 0;
        if(n >= 1) cout << 1, b = true;
        else if(b) cout << 0;
    }
    return 0;
}
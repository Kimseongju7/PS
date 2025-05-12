#include<iostream>
using namespace std;

char G[5] = {'a', 'e', 'i', 'o', 'u'};

bool isGather(char c){
    for(int i = 0; i < 5; i++) if(c == G[i]) return true;
    return false;
}

bool A(string s){
    for(auto i : s){
        if(isGather(i)) return true;
    }
    return false;
}



bool B(string s, int len){
    bool ret = true;
    bool a, b, c;
    a = isGather(s[0]); b = isGather(s[1]);
    for(int i = 2; i < len; i++){
        c = isGather(s[i]);
        if(a == b && b == c) return false;
        a = b; b = c;
    }
    return true;;   
}

bool C(string s, int len){
    for(int i = 0; i < len - 1; i++){
        if(s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o') return false;
    }
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    int len;
    bool valid;
    while (true){
        cin >> s;
        if(s == "end") break;
        valid = true; len = s.length();

        valid = valid && A(s);
        valid = valid && B(s, len);
        valid = valid && C(s, len);

        cout << "<" << s << "> is " << (valid ? "" : "not ") << "acceptable.\n";

    }
    
    return 0;
}
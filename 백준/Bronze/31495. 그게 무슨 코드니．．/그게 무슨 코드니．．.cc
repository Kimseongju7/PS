#include<iostream>
#include<map>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    getline(cin, s);
    if(s[0] == '\"' && s[s.length() - 1] == '\"' && s.length() > 2) {for(auto i : s) if(i != '\"') cout << i;}
    else cout << "CE";
    return 0;
}
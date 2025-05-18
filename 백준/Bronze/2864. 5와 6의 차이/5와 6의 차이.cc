#include<iostream>
#include<string>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s, s1; int a, b;
    cin >> s >> s1;
    for(int i = 0; i < s.length(); i++) if(s[i] == '6' || s[i] == '5') s[i] = '5';
    for(int i = 0; i < s1.length(); i++) if(s1[i] == '6' || s1[i] == '5') s1[i] = '5';
    cout << stoi(s) +  stoi(s1) << ' ';
    for(int i = 0; i < s.length(); i++) if(s[i] == '6' || s[i] == '5') s[i] = '6';
    for(int i = 0; i < s1.length(); i++) if(s1[i] == '6' || s1[i] == '5') s1[i] = '6';
    cout << stoi(s) +  stoi(s1);
    return 0;
}
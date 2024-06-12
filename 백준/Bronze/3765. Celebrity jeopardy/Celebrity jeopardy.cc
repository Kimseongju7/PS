#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    while(1){
        getline(cin, s);
        if(cin.eof()) break;
        cout << s << '\n';
    }
    return 0;
}
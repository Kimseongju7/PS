#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    while(1){
        getline(cin, s);
        if(cin.eof()) break;
        cout << s << '\n';
    }
    return 0;
}
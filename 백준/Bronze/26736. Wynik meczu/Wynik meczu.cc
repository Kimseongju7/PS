#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a = 0, b = 0; string s;
    cin >> s;
    for(auto i : s){
        if(i == 'A') ++a;
        else ++b;
    }
    cout <<a<< " : " << b;
    return 0;
}
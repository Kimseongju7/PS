#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; int b = 0, w = 0;
    cin >> s;
    for(auto i : s){
        if(i == 'C') ++w;
        else if(i == 'B') ++b;  
    }
    cout << w / 2 + b / 2;
    return 0;
}
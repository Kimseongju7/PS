#include<iostream>
#include<string>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; int n;
    while(true){
        cin >> s;
        if(s == "0") break;
        while(true){
            n = 0;
            for(int i = 0; i < s.length(); i++){
                n += s[i] - '0';
            }
            if(n < 10) break;
            else s = to_string(n);
        }
        cout << n << '\n';
    }
        
    return 0;
}
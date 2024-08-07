#include<iostream>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    cin >> s;
    cout << s[0];
    for(int i = 1; i < s.size(); ++i){
        if(!(i % 10)) cout << endl;
        cout << s[i];
    }
    return 0;   
}
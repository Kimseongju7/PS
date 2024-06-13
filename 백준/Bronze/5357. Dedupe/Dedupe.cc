#include<iostream>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    string s;
    while(T--){
        cin >> s;
        for(int i = 0; i < s.size(); ++i){
            if(i + 1 == s.size() || s[i] != s[i + 1]) cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
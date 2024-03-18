#include <iostream>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    bool s[21] = {};
    int N, x;
    cin >> N;
    while(N--){
        cin >> str; 
        if(str == "add"){
            cin >> x;
            s[x] = true;
        }
        else if(str == "remove"){
            cin >> x;
            s[x] = false;
        }
        else if(str == "check"){
            cin >> x;
            if(s[x]) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(str == "toggle"){
            cin >> x;
            if(s[x]) s[x] = false;
            else s[x] = true;
        }
        else if(str == "all"){
            memset(s, 1, sizeof(s));
        }
        else{
            memset(s, 0, sizeof(s));
        }   
    }
    return 0;
}
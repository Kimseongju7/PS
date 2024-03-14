#include <iostream>
#include <map>
#include <algorithm>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int len, cnt = 0, al[26] = {};
    char cen = '\0', res[55] = {};
    string s;
    cin >> s;
    len = s.size();
    for(int i = 0; i < len; ++i){
        ++al[s[i] - 'A'];
    }
    //for(char i = 0; i < 26; ++i) cout << al[i] << ' ';
    //cout << endl;
    if(len % 2 == 0){ //짝수 길이
        for(char i = 0; i < 26; ++i){
            if(al[i] % 2 != 0) {
                cout << "I'm Sorry Hansoo" << endl;
                return 0;
            }
        }
    }   
    else {
        for(char i = 0; i < 26; ++i){
            if(al[i] % 2 != 0) {
                ++cnt;
                if(cen == '\0') cen = char(i + 'A');
            }
        }
       //cout << "cen : " << cen << ", cnt : " << cnt << endl;
        if(cnt > 1){
            cout << "I'm Sorry Hansoo" << endl;
            return 0;
        }
    }
    //cout << "res" << endl;
    int ai = 0, ci = 0;
    while(ai < 26){
        if(al[ai] > 1){
            res[ci++] = char(ai + 'A');
            al[ai] -= 2;
        }
        else ++ai;
    }
    cout << res;
    reverse(res, res + (len / 2));
    if(len % 2 == 0){ //짝수
        cout << res << endl;
    }
    else {
        cout << cen << res << endl;
    }
    return 0;
}
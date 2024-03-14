#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;
#define endl '\n'
//337 33
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long N, num, tmp1, tmp2;
    string stmp1, stmp2, tmp, *s;
    cin >> N;
    s = new string[N + sizeof(string) * 10];
    for(int i = 0; i < N; ++i){
        cin >> s[i];
    }
    for(int i = 0; i < N - 1; ++i){
        for(int j = 0; j < N - 1 - i; ++j){
            stmp1 = s[j] + s[j + 1];
            stmp2 = s[j + 1] + s[j];
            tmp1 = stoull(stmp1);
            tmp2 = stoull(stmp2);
            if(tmp1 < tmp2){
                tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }
    if(s[0] == "0") cout << 0 << endl;
    else {
        for(int i = 0; i < N; ++i) cout << s[i];
        cout << endl;
    }
    delete[] s;
    return 0;
}
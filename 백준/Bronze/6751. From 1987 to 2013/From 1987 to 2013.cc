#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    bool num[10] = {};
    int N, sum;
    string s;
    cin >> N;
    for(int i = N + 1; ; ++i){
        memset(num, 0, sizeof(num));
        s = to_string(i);
        sum = 0;
        for(int i = 0; i < s.size(); ++i) num[s[i] - '0'] = true;
        for(int i = 0; i < 10; ++i) sum += num[i];
        if(sum == s.size()){
            cout << i;
            return 0;
        }
    }
    return 0;
}
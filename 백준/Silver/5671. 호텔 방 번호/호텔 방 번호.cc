#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int C[10] = {}, N, M, cnt;
    bool valid;
    string s;
    while (true)
    {
        /* code */
        cnt = 0;
        cin >> N >> M;
        if(cin.eof()) break;
        for(int i = N; i <= M; ++i){
            s = to_string(i);
            memset(C, 0, sizeof(C));
            valid = true;
            for(int j = 0; j < s.length(); ++j){
                if(C[s[j] - '0']) {
                    valid = false;
                    break;
                }
                C[s[j] - '0']++;
            } 
            if(valid) ++cnt;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}
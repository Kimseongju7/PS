#include<iostream>
#include<map>
#include<queue>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    map<char, char> m;
    int N, dap, cnt;
    string s;
    queue<char> q;
    while(true){
        m.clear(); dap = 0; 
        while(!q.empty()) q.pop();
        cin >> N;
        if(!N) break;
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] == 0){ //첫 도착
                if(cnt < N){ //사용 가능
                    m[s[i]] = 2;
                    ++cnt;
                }
                else {
                    m[s[i]] = 1;
                    q.emplace(s[i]);
                }
            }
            else if(m[s[i]] == 1){ //대기중
                dap++;
                m[s[i]] = 0;
            }
            else if(m[s[i]] == 2){ //사용 중
                m[s[i]] = 0;
                while(true){
                    if(q.empty()) {
                        --cnt;
                        break;
                    }
                    char c = q.front(); q.pop();
                    if(m[c] == 1){
                        m[c] = 2;
                        break;
                    }
                }
            }
        }
        if(dap) cout << dap << " customer(s) walked away.\n";
        else cout << "All customers tanned successfully.\n";
    }
    return 0;
}
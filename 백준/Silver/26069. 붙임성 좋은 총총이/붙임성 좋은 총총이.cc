#include<iostream>
#include<map>
using namespace std;
map<string, bool> m;
int dap = 1, N;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    m["ChongChong"] = true;
    while(N--){
        string s1, s2;
        cin >> s1 >> s2;
        if(m[s1] && !m[s2]){
            ++dap;
            m[s2] = true;
        }
        else if(!m[s1] && m[s2]){
            ++dap;
            m[s1] = true;
        }
    }
    cout << dap;
    return 0;
}
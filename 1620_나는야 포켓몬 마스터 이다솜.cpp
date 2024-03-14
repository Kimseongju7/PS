#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, int> m;
    int N, M;
    string s;
    cin >> N >> M;
    vector<string> v(N + 10);
    for(int i = 1; i <= N; ++i){
        cin >> s;
        m[s] = i;
        v[i] = s;
    }
    for(int i = 0; i < M; ++i){
        cin >> s;
        if(('0' <= s[0]) && (s[0] <= '9')) cout << v[stoi(s)] << '\n';
        else cout << m[s] << '\n';
    }
    return 0;
}
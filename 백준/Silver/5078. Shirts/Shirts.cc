#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int W, M; string t;
    while(true){
        vector<string> s, m, l;
        cin >> W;
        if(W == 0) break;
        s.clear(); m.clear(); l.clear();
        for(int i = 1; i <= W; ++i){
            cin >> t;
            if(t[0] == 'S') s.emplace_back(t);
            else if(t[0] == 'M') m.emplace_back(t);
            else l.emplace_back(t);

        }
        cin >> M;
        for(int i = 1; i <= M; ++i) {
            cin >> t;
            if(t[0] == 'S') s.emplace_back(t);
            else if(t[0] == 'M') m.emplace_back(t);
            else l.emplace_back(t);
        }
        sort(s.begin(), s.end());
        sort(m.begin(), m.end());
        sort(l.begin(), l.end());
        for(auto i : s) cout << i << ' ';
        for(auto i : m) cout << i << ' ';
        for(auto i : l) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
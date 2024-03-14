#include <iostream>
#include <set>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, tmp;
    set<int> s;
    cin >> a >> b;
    for(int i = 0; i < a; ++i){
        cin >> tmp;
        s.insert(tmp);
    }
    for(int i = 0; i < b; ++i){
        cin >> tmp;
        auto it = s.find(tmp);
        if(it != s.end()) s.erase(it);
    }
    cout << s.size() << endl;
    for(auto it = s.begin(); it != s.end(); ++it) cout << *it << ' ';
    return 0;
}
#include<iostream>
#include<set>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    set<string> s;
    s.insert("Never gonna give you up");
    s.insert("Never gonna let you down");
    s.insert("Never gonna run around and desert you");
    s.insert("Never gonna make you cry");
    s.insert("Never gonna say goodbye");
    s.insert("Never gonna tell a lie and hurt you");
    s.insert("Never gonna stop");
    int N; cin >> N; cin.ignore();
    while(N--){
        string str;     
        getline(cin, str);
        if(!s.count(str)){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
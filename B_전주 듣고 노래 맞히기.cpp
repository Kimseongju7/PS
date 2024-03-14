#include<iostream>
#include <map>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, T;
    string name, key;
    char t[100];
    map<string, string> data;
    map<string, int> cnt;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> T >> name >> key;
        for(int i = 0; i < 2; ++i) {
            char tmp;
            cin >> tmp;
            key.push_back(tmp);
        }
        data[key] = name;
        cnt[key]++;
        cin.getline(t, sizeof(t), '\n');
    }
    for(int i = 0; i < m; ++i){
        cin >> key;
        for(int i = 0; i < 2; ++i){
            char tmp;
            cin >> tmp;
            key.push_back(tmp);
        }
        if(cnt[key] == 1){
            cout << data[key] << endl;
        }
        else if(cnt[key] > 1) cout << '?' << endl;
        else cout << '!' << endl;
    }
    return 0;
}
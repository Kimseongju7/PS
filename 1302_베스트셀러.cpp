#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int> m;
    string s;
    int N, ma = -1;
    cin >> N; 
    while(N--){
        cin >> s;
        m[s]++;
    }
    for(auto i : m) ma = max(ma, i.second);
    for(auto i : m){
        if(i.second == ma){
            s = i.first;
            break;
        }
    }
    cout << s << endl;
    return 0;
}
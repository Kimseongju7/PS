#include <iostream>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, len, res;
    char str[1010][111];
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> str[i];
    }
    len = strlen(str[0]);
    for(int i = 1; i < 100; ++i) {
        set <int> s;
        for(int j = 0; j < N; ++j){
            int num = atoi(&str[j][len - i]);
            s.insert(num);
        }
        if(s.size() == N){
            res = i;
            break;
        }
    }
    cout << res << endl;
    return 0;
}
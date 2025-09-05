#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    int N; string s;
    for(int i = 1; i <= T; i++){
        cin >> N >> s;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == 'c') N++;
            else if(s[j] == 'b') N--;
        }
        cout << "Data Set " << i << ":\n" << N << "\n\n";
    }
    return 0;
}
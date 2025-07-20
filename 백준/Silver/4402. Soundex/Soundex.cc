#include<iostream>
#include<set>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    set<int> s[7];
    int A[22] = {};
    s[0] ={'A', 'E', 'I','O', 'U', 'H', 'W', 'Y'}, 
    s[1] = {'B', 'F', 'P', 'V'}, 
    s[2] = {'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'}, 
    s[3] = {'D', 'T'}, 
    s[4] = {'L'},
    s[5]= {'M', 'N'},    
    s[6] = {'R'};
    while(true){
        string str;
        cin >> str;
        if(cin.eof()) break;
        int len = str.length();
        for(int i = 0; i < len; i++){
            for(int j = 0; j < 7; j++){
                if(s[j].count(str[i])){
                    A[i] = j;
                    if(j == 0) break;
                    if(i != 0 &&  A[i] == A[i - 1]) break;
                    cout << j;
                    break;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
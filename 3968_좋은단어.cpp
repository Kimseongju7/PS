#include<iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    char c;
    int T, cnt = 0;
    cin >> T;
    cin.get();
    while(T--){
        stack<char> st;
        while((c = cin.get()) != '\n'){
            if(st.empty()) st.push(c);
            else{
                if(c == st.top()){
                    st.pop();
                }
                else st.push(c);
            }
        }
        if(st.empty()) ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
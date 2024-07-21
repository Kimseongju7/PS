#include<iostream>
#include<map>
using namespace std;
int dap, N;
map<string, bool> C;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    string s;
    for(int i = 0; i < N; ++i){
        cin >> s;
        if(s == "ENTER") C.clear();
        else if(!C[s]) ++dap, C[s] = true;
    }
    cout << dap;
    return 0;
}
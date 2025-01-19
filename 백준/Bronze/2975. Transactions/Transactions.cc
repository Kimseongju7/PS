#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a, b; char c;
    while(true){
        cin >> a >> c >> b;
        if(a == 0 && c == 'W' && b == 0) break;
        if(c == 'W'){
            if(a - b < -200) cout << "Not allowed";
            else cout << a - b;
        }
        else cout << a + b;
        cout << '\n';
    }
    return 0;
}
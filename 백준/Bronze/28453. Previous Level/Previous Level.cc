#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, a; cin >> N;
    while(N--){
        cin >> a;
        if(a < 250) cout << 4;
        else if(a < 275) cout << 3;
        else if(a < 300) cout << 2;
        else cout << 1;
        cout << '\n';
    }
    return 0;   
}
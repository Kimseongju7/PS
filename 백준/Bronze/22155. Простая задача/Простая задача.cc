#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, a, b; cin >> N;
    while(N--){
        cin >> a >> b;
        if((a <= 1 && b <= 2) || (a <= 2 && b <= 1)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;   
}
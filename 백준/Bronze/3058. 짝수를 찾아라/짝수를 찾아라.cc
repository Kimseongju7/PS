#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T, sum, m, t;
    cin >> T;
    while(T--){
        sum = 0, m = 111;
        for(int i = 1; i <= 7; ++i){
            cin >> t;
            if(!(t & 1)){
                m = min(t, m);
                sum += t;
            }
        }
        cout << sum << ' ' << m << '\n';
    }
    return 0;
}
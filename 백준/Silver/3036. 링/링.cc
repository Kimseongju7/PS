#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, a, b, c; cin >> N >> a;
    for(int i = 1; i < N; i++){
        cin >> c; b = a;
        for(int j = 2; j <= max(b, c); ){
            if(b % j == 0 && c % j == 0) b /= j, c /= j;
            else j++;
        }
        cout << b << '/' << c << '\n';
    }

    return 0;
}
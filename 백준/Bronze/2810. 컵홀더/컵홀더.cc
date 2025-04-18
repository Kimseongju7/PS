#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; char c; cin >> N;
    int cp = 0;
    for(int i = 1; i <= N; ++i){
        cin >> c;
        if(c == 'L') {
            ++cp;
            cin >> c;
            ++i;
        }
    }

    cout << min(N, N - (cp - 1)) ;
}
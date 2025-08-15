#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T, N, sum, n; cin >> T;
    while(T--){
        sum = 0;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> n;
            sum += n;
        }
        cout << sum << '\n';
    }
    return 0;
}
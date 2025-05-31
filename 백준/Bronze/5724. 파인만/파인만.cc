#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    int n;
    while(true){
        cin >> N;
        int sum = 0;
        if(!N) break;
        for(int i = 1; i <= N; i++){
            n = N - i + 1;
            // cout << i << ' ' << n * n << '\n';
            sum += n * n;
        }
        cout << sum << '\n';
    }
    return 0;
}
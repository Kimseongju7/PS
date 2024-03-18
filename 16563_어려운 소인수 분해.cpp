#include <iostream>
#define endl '\n'
#define M 5000010
using namespace std;
int prime[M] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n;
    for(int i = 2; i < M; ++i){
        if(prime[i]) continue;
        for(int j = i; j < M; j += i){
            if(!prime[j]) prime[j] = i;
        }  
    } 
    cin >> T;
    while(T--){
        cin >> n;
        while(n > 1){
            cout << prime[n] << ' ';
            n /= prime[n];
        }
        cout << endl;
    }

    return 0;
}
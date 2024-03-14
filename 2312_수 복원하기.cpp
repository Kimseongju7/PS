#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, arr[101010], N;
    cin >> T;
    while(T--){
        memset(arr, 0, sizeof(arr));
        cin >> n;
        N = n;
        for(int i = 2; n > 1;){
            if(n % i == 0){
                ++arr[i];
                n /= i;
            }
            else ++i;
        }
        for(int i = 2; i <= N; ++i){
            if(arr[i] != 0) cout << i << " " << arr[i] << '\n';
        }
    }
}
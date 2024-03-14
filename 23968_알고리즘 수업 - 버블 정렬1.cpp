#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr);

inline void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
int main(){
    FASTIO
    int k, *arr, N, cnt = 0;
    cin >> N >> k;
    arr = new int[N + 1];
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    for(int i = N; i >= 2; --i){
        for(int j = 1; j <= i - 1; ++j){
            if(arr[j] > arr[j + 1]) {
                ++cnt;
                swap(arr[j], arr[j + 1]);
                if(cnt == k){
                    for(int i = 1; i <= N; ++i) cout << arr[i] << " ";
                    delete[] arr;
                    return 0;
                }
            }
        }
    }
    if(cnt < k) cout << -1 << endl;
    delete[] arr;
    return 0;
}
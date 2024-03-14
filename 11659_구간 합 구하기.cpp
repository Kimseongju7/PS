#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int *arr, T, N, n, x, y, *sum, res;
    cin >> N >> T;
    arr = new int[N + 1];
    sum = new int[N + 1];
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    sum[0] = arr[0] = 0;
    sum[1] = arr[1];
    for(int i = 2; i <= N; ++i) sum[i] = sum[i - 1] + arr[i];
    while(T--){
        cin >> x >> y;
        res = sum[y] - sum[x - 1];
        cout << res << '\n';
    }
    delete[] arr;
    delete[] sum;
    return 0;
}
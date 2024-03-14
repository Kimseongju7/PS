#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, *arr, cnt, res;
    cin >> N;
    arr = new int[N + 10];
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
    }
    sort(arr, arr + N);
    res = 0;
    for(int i = 0; i < N; ++i){
        cnt = 1;
        for(int j = i + 1; j < i + 5; ++j){
            if(arr[j] - arr[i] < 5 && arr[j] - arr[i] > 0) { //범위를 넘어가면 arr[j] 값이 0이됨
                ++cnt;
            }
        }
        res = max(res, cnt);
    }
    cout << 5 - res << endl;
    delete[] arr;
    return 0;
}
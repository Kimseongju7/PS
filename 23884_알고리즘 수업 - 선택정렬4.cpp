#include <iostream>
#include <map>
#include<algorithm>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, k, *arr, cnt = 0, index, tmp, *sarr;
    cin >> N >> k;
    map<int, int> indexArr;
    arr = new int[N + 1];
    sarr = new int[N + 1];
    for(int i = 1; i <= N; ++i) {
        cin >> arr[i];
        sarr[i] = arr[i];
        indexArr[arr[i]] = i;
    }
    sort(sarr + 1, sarr + N + 1);
    for(int i = N; i >= 1; --i){
        if(arr[i] != sarr[i]) {
            ++cnt;
            index = indexArr[sarr[i]];
            indexArr[sarr[i]] = i;
            indexArr[arr[i]] = index;
            tmp = arr[i];
            arr[i] = arr[index];
            arr[index] = tmp;
            if(cnt == k){
                break;
            }
        }
    }
    if(cnt < k) cout << -1 << endl;
    else {
        for(int i = 1; i <= N; ++i){
            cout << arr[i] << ' ';
        }
    }
    delete[] arr;
    delete[] sarr;
    return 0;
} 
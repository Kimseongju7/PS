#include<iostream>
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;

void printArr(int * arr, int N){
    for(int i = 1; i <= N; ++i) cout << arr[i] << ' ';
}

int main(){
    FASTIO;
    int N, *arr, k, cnt = 0, loc, newitem;
    cin >> N >> k;
    arr = new int[N + 1];
    for(int i = 1; i <= N; ++i) cin>> arr[i];
    for(int i = 2; i <= N; ++i){
        loc = i - 1;
        newitem = arr[i];
        while(1 <= loc && newitem < arr[loc]){
            arr[loc + 1] = arr[loc], ++cnt;
            if(cnt == k) {
                printArr(arr, N);
                return 0;
            }
            --loc;
        }
        if(loc + 1 != i) arr[loc + 1] = newitem, ++cnt;
        if(cnt == k){
            printArr(arr, N);
            break;
        }
    }
    if(cnt < k) cout << -1 << endl;
    delete[] arr;
    return 0;
}
#include <iostream>
using namespace std;
int cnt = 0, k, N;

void merge(int *arr, int p, int q, int r){
    int tmp[505050];
    int i = p, j = q + 1, t = 1;
    while(i <= q && j <= r){
        if(arr[i] <= arr[j]) tmp[t++] = arr[i++];
        else tmp[t++] = arr[j++];
    }
    while(i <= q) tmp[t++] = arr[i++];
    while(j <= r) tmp[t++] = arr[j++];
    i = p, t = 1;
    while(i <= r) {
        ++cnt;
        arr[i++] = tmp[t++];  
        if(cnt == k) {
            for(int i = 1; i <= N; ++i) cout << arr[i] << ' ';
            exit(0);
        }
    }
}

void mergeSort(int *arr, int p, int r){
    if(p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main(){
    int *arr;
    cin >> N >> k;
    arr = new int[N + 1];
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    mergeSort(arr, 1, N);
    if(cnt < k) cout << -1 << endl;
    delete[] arr;
    return 0;
}
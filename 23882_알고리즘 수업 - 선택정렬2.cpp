#include <iostream>
using namespace std;

void myMax(int *arr, int N, int &mi){
    int m = arr[1];
    mi = 1;
    for(int i = 1; i <= N; ++i){
        if(m <= arr[i]){
            m = arr[i];
            mi = i;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int * arr, N, k;
    cin >> N >> k;
    int mi = 0;
    unsigned long long cnt = 0;
    arr = new int[N + 10];
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    for(int i = N; i >= 2; --i){
        myMax(arr, i, mi);
        if(mi != i){    
            int tmp = arr[mi];
            arr[mi] = arr[i];
            arr[i] = tmp;
            ++cnt;
            if(cnt == k){
                break;
            }
        }
    }
    if(cnt < k) cout << -1 << endl;
    else {
        for(int i = 1; i <= N; ++i) cout << arr[i] << ' ';
        cout << endl;
    }
    delete[] arr;
    return 0;
}
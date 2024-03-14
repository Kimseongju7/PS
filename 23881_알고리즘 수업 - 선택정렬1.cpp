#include <iostream>
#define endl '\n'
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
                cout << arr[mi] << ' ' << arr[i] << endl;
                return 0;
            }
        }
    }
    if(cnt < k) cout << -1 << endl;
    delete[] arr;
    return 0;
}
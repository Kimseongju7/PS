#include<iostream>
using namespace std;

int main(){
    int N, k, cnt = 0, p = 2;
    cin >> N >> k;
    int arr[N + 1];
    for(int i = 2; i <= N; ++i) arr[i] = i;
    for(int p = 2; p <= N; ++p){
        if(arr[p] == 0) continue;
        for(int i = 1; p * i <= N; ++i){
            if(arr[p * i]){
                arr[p * i] = 0;
                ++cnt;
            }
            if(cnt == k) {
                cout << p * i << endl;
                p = N + 1;
                break;
            }
        }
    }
    return 0;
}
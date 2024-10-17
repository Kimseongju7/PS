#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int sum = 0, arr[9], d1, d2;
    for(int i = 0 ;i < 9; ++i){
        cin >> arr[i]; sum += arr[i];
    }
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(i == j) continue;
            if(sum - arr[i] - arr[j] == 100){
                d1 = arr[i]; d2 = arr[j];
                i = 10;
                break;
            }
        }
    }
    sort(arr, arr + 9);
    for(int i = 0; i < 9; ++i){
        if(arr[i] != d1 && arr[i] != d2) cout << arr[i] << '\n';
    }
    return 0;
}
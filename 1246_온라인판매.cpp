#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, res, *arr, rest;
    cin >> n >> m;
    arr = new int[m + 1];
    arr[m] = 0;
    for(int i = 0; i < m; ++i) cin >> arr[i];
    sort(arr, arr + m);
    reverse(arr, arr + m); 
    rest = 0;
    for(int i = 0; i < m; ++i){
        if(i + 1 > n) break;
        if(arr[i] * (i + 1) >= rest) {
            res = arr[i];
            rest = res  * (i + 1);
        }
    }
    cout << res << " " << rest << endl;
    delete[] arr;
    return 0;
}
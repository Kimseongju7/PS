#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, x, i, j, cnt = 0, tmp;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cin >> x;
    sort(&arr[0], &arr[n]);
    i = 0;
    j = n - 1;
    while(i < j){
        tmp = arr[i] + arr[j];
        if(tmp == x){
            ++i, --j;
            ++cnt;
        }
        else if (tmp < x){
            ++i;
        }
        else --j;
    }
    cout << cnt << endl;
    return 0;
}
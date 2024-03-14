#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[5], avg = 0, cen;
    for(int i = 0; i < 5; ++i) cin >> arr[i];
    sort(arr, arr + 5);
    for(auto i : arr) avg += i;
    avg /= 5;
    cen = arr[2];
    cout << avg << '\n' << cen << endl;
    return 0;
}
#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long X, Y, Z, dap = -1; cin >> X >> Y;
    Z = Y * 100 / X;
    long long left = 0, right = 1000000000, tmpz;
    while(left <= right){
        long long mid = (left + right) / 2;
        // cout << left << ' ' << mid << ' ' << right << endl;
        tmpz = (Y + mid) * 100 / (X + mid);
        if(tmpz > Z){
            dap = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << dap;
    return 0;
}
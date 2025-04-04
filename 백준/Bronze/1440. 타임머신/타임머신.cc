#include<iostream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a[3]; char ch;
    cin >> a[0] >> ch >> a[1] >> ch >> a[2];
    int dap = 0;
    for(int i = 0; i < 3; ++i){
        if(a[i] > 12 || a[i] < 1) continue;
        for(int j = 0; j < 3; ++j){
            if(i == j) continue;
            if(a[j] > 59) continue;
            for(int k = 0; k < 3; ++k){
                if(k == i || k == j) continue;
                if(a[k] > 59) continue;
                ++dap;
            }
        }
    }
    cout << dap;
    return 0;
}
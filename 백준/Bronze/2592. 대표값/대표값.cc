#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int cnt[1010] = {}, maxi = 0, m = 0, sum = 0;
    for(int i = 0; i < 10; ++i){
        int t;
        cin >> t;
        sum += t;
        cnt[t]++;
    }
    cout << sum / 10;
    for(int i = 0; i <= 1000; i+= 10){
        if(m < cnt[i]){
            m = cnt[i];
            maxi = i;
        }
    }
    cout << endl << maxi;
    return 0;
}
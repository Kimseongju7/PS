#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, R[101010], dap;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> R[i];
    sort(R, R + N);
    for(int i = 0; i < N; ++i){
        int t = R[i] * (N - i);
        dap = max(t, dap);
    }
    cout << dap;
    return 0;
}
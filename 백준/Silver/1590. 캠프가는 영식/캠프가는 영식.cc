#include<iostream>
using namespace std; 
bool bus[2020202];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, T, S, I, C, index = 1e9, dap; cin >> N >> T; dap = T - 1;
    
    for(int i = 0; i < N; i++){
        cin >> S >> I >> C;
        for(int j = 0; j < C; j++){
            if(S + I * j >= T)index = min(index, S + I * j);
        }
        
    }
    for(int i = index; i < 2020202; i++) bus[i] = true;
    int left = T, right = 2020202;
    while(left <= right){
        int mid = (left + right) / 2;
        // cout << left << ' ' << mid << ' ' << right << endl;
        if(bus[mid]){
            dap = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    // cout << index << endl;
    // cout << dap << endl;
    cout << dap - T;
    return 0;
}
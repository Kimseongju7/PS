#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    int arr[3];
    cout << "Gnomes:\n";
    while(T--){
        for(int i = 0; i < 3; ++i) cin >> arr[i]; 
        if(arr[2] >= arr[1] && arr[1] >= arr[0]) cout << "Ordered\n";
        else if(arr[2] <= arr[1] && arr[1] <= arr[0]) cout << "Ordered\n";
        else cout << "Unordered\n";
        
    }
    return 0;
}
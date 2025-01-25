#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int R, C, T, dap = 0; cin >> R >> C;
    int arr[R + 1][C + 1];
    for(int i = 1; i <= R; ++i) for(int j = 1; j <= C; ++j) cin >> arr[i][j];
    vector<int> v;
    cin >> T;
    for(int i = 1; i + 2 <= R; ++i){
        for(int j = 1; j + 2 <= C; ++j){
            v.clear();
            for(int k = i; k < i + 3; ++k){
                for(int l = j; l < j + 3; ++l){
                    v.emplace_back(arr[k][l]);
                }
            }
            sort(v.begin(), v.end());
            if(v[4] >= T) ++dap;
        }
    }
    cout << dap;
    return 0;
}
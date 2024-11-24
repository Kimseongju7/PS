#include<iostream>
using namespace std;
int N,d[1111][1111] ={}, arr[1111][1111], M;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j) cin >> arr[i][j];
    }
    d[1][1] = arr[1][1];
    for(int i = 2; i <= N; ++i) {
        d[1][i] = d[1][i - 1] + arr[1][i];
        d[i][1] = d[i - 1][1] + arr[i][1];
    }
    for(int i = 2; i <= N; ++i){
        for(int j = 2; j <= N; ++j){
            d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + arr[i][j];
        }
    }
    // for(int i = 1; i <= N; ++i){
    //     for(int j = 1; j <= N; ++j) cout << d[i][j] << ' ';
    //     cout << endl;
    // }
    while(M--){
        int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        // cout << d[x2][y2] << ' ' << d[x1 - 1][y2]  << ' ' <<  d[x2][y1 - 1]  << ' '<< d[x1 - 1][y1 - 1] << '\n';
        cout << d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}
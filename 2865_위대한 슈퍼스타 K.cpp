#include <iostream>
#include <algorithm>
#include<iomanip>
#include<cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, index;
    double res = 0, arr[111], av;
    cin >> n >> m >> k;
    memset(arr, 0, sizeof(double) * (n + 1));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> index >> av;
            arr[index] = max(arr[index], av);
        }
    }
    sort(arr + 1, arr + n + 1, greater<double>());
    for(int i = 1; i <= k; ++i) res += arr[i];
    cout << fixed << setprecision(1);
    cout << res;
    return 0;
}
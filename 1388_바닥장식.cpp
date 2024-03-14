#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    int n, m, res = 0;
    char pre;
    cin >> n >> m;
    char **arr;
    arr = (char **)malloc(sizeof(char *) * n);
    for(int i = 0; i < n; ++i) arr[i] = (char *)malloc(sizeof(int) * m);
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    pre = arr[0][0];
    for(int i = 0; i < n; ++i){
        pre = arr[i][0];
        for(int j = 0; j < m; ++j){
            if(pre == '-'){
                if(arr[i][j] == '|') ++res;
            }
            pre = arr[i][j];
        }
        if(pre == '-') ++res;
    }
    pre = arr[0][0];
    for(int i = 0; i < m; ++i){
        pre = arr[0][i];
        for(int j = 0; j < n; ++j){
            if(pre == '|'){
                if(arr[j][i] == '-') ++res;
            }
            pre = arr[j][i];
        }
        if(pre == '|') ++res;
    } 
    cout << res << endl;
    for(int i = 0; i < n; ++i) free(arr[i]);
    free(arr);
    return 0;
}
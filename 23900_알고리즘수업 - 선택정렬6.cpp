#include <iostream>
#include <map>
#include<algorithm>
#define endl '\n'
using namespace std;

int cmpUpdata(map<int, bool> &cmp, int *arr, int * b, int &index, int& i){
    int re = 0;
    //바뀌었으면 다른게 같아지거나 같은게 달라지거나
    if(arr[i] == b[i]){
        --re;
        cmp[i] = true;
    }
    else {
        if(cmp[i]){
            ++re;
            cmp[i] = false;
        }
    }
    if(arr[index] == b[index]){
        --re;
        cmp[index] = true;
    }
    else {
        if(cmp[index]){
            ++re;
            cmp[index] = false;
        }
    }
    return re;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, *arr, cnt = 0, index, tmp, *sarr, *b;
    cin >> N;
    map<int, int> indexArr;
    map<int, bool> cmp;
    arr = new int[N + 1];
    sarr = new int[N + 1];
    b = new int[N + 1];
    for(int i = 1; i <= N; ++i) {
        cin >> arr[i];
        sarr[i] = arr[i];
        indexArr[arr[i]] = i;
    }
    for(int i = 1; i <= N; ++i) cin >> b[i];
    for(int i = 1; i <= N; ++i){
        if(arr[i] != b[i]){
            cmp[i] = false;
            ++cnt; //다른 요소의 개수
        }
        else cmp[i] = true;
    }
    if(cnt == 0){
        cout << 1 << endl;
        return 0;
    }
    sort(sarr + 1, sarr + N + 1);
    for(int i = N; i >= 1; --i){
        if(arr[i] != sarr[i]) {
            index = indexArr[sarr[i]];
            indexArr[sarr[i]] = i;
            indexArr[arr[i]] = index;
            tmp = arr[i];
            arr[i] = arr[index];
            arr[index] = tmp;
            cnt += cmpUpdata(cmp, arr, b, index, i);
            if(cnt == 0) break;
        }
    }
    if(cnt == 0) cout << 1 << endl;
    else cout << 0 << endl;
    delete[] arr;
    delete[] sarr;
    delete[] b;
    return 0;
} 
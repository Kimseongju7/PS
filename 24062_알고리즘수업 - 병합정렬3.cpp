#include <iostream>
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;

class CMP{
    private :
        bool cmp[505050]; 
        int cmpArr[505050];
        int cnt; //다른 것의 개수
    public :
        int N;
        CMP(int n = 0) : N(n) { cnt = 0; }
        ~CMP() { }
        void cmpInit(int * arr);
        int size() { return cnt; }
        void inputArr(int n, int i) { cmpArr[i] = n; }
        void update(int *ary, int i); //배열과 인덱스를 주고 같아졌으면 true로 바꾼 뒤 size 줄이기, 달라졌으면 그 반대
};

void CMP::update(int *ary, int i){
    if(ary[i] == cmpArr[i] && !cmp[i]){
        cmp[i] = true;
        --cnt;
    }
    else if(ary[i] != cmpArr[i] && cmp[i]){
        cmp[i] = false;
        ++cnt;
    }
}

void CMP::cmpInit(int *arr){
    for(int i = 1; i <= N; ++i){
        if(cmpArr[i] != arr[i]) cmp[i] = false, ++cnt;
        else cmp[i] = true;
    }
}

int N;
CMP cmp;

void merge(int *arr, int p, int q, int r){
    int tmp[505050];
    int i = p, j = q + 1, t = 1;
    while(i <= q && j <= r){
        if(arr[i] <= arr[j]) tmp[t++] = arr[i++];
        else tmp[t++] = arr[j++];
    }
    while(i <= q) tmp[t++] = arr[i++];
    while(j <= r) tmp[t++] = arr[j++];
    i = p, t = 1;
    while(i <= r) {
        arr[i++] = tmp[t++];  
        cmp.update(arr, i - 1);
        if(!cmp.size()) {
            cout << 1 << endl;
            exit(0);
        }
    }
}

void mergeSort(int *arr, int p, int r){
    if(p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main(){
    FASTIO
    int *arr, num;
    cin >> N;
    arr = new int[N + 1];
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    cmp.N = N;
    for(int i = 1; i <= N; ++i) {
        cin >> num;
        cmp.inputArr(num, i);
    }
    cmp.cmpInit(arr);
    if(!cmp.size()) {
        cout << 1 << endl;
        return 0;
    }
    mergeSort(arr, 1, N);
    if(cmp.size()) cout << 0 << endl;
    delete[] arr;
    return 0;
}
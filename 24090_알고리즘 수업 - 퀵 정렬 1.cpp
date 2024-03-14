#include <iostream>
using namespace std;
#define SWAP(x, y) { int tmp = x; x = y; y = tmp; }
#define endl '\n'

class CMP{
    private :
        bool cmp[10101]; 
        int cmpArr[10101];
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

int parti(int *arr, int p, int r){
    int x = arr[r];
    int i = p - 1;
    for(int j = p; j <= r - 1; ++j){
        if(arr[j] <= x){
            ++i;
            SWAP(arr[i], arr[j]);
            cmp.update(arr, i);
            cmp.update(arr, j);
            if(!cmp.size()){
                cout << 1 << endl;
                exit(0);
            }
        }
    }
    if(i + 1 != r) {
        SWAP(arr[i + 1], arr[r]);
        cmp.update(arr, i + 1);
        cmp.update(arr, r);
        if(!cmp.size()){
            cout << 1 << endl;
            exit(0);
        }
    }
    return i + 1;
}

void quick_sort(int *arr, int p, int r){
    if(p < r){
        int q = parti(arr, p, r);
        quick_sort(arr, p, q - 1);
        quick_sort(arr, q + 1, r);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
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
    quick_sort(arr, 1, N);
    cout << 0 << endl;
    delete[] arr;
    return 0;
}
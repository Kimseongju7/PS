#include<iostream>
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;

class CMP{
    private :
        bool *cmp; 
        int *cmpArr;
        int N; //배열의 크기
        int cnt; //다른 것의 개수
    public :
        CMP(int n = 0) : N(n) { cmp = new bool[N + 1]; cmpArr = new int[N + 1]; cnt = 0; }
        ~CMP() { delete[] cmp; delete[] cmpArr; }
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

int main(){
    int N, *arr, num, loc, newitem;
    cin >> N;
    CMP cmp(N);
    arr = new int[N + 1];
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    for(int i = 1; i <= N; ++i) {
        cin >> num;
        cmp.inputArr(num, i);
    }
    cmp.cmpInit(arr);
    if(!cmp.size()) {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 2; i <= N; ++i){
        loc = i - 1;
        newitem = arr[i];
        while(1 <= loc && newitem < arr[loc]){
            arr[loc + 1] = arr[loc];
            cmp.update(arr, loc + 1);
            if(!cmp.size()){
                cout << 1 << endl;
                return 0;
            }
            --loc;
        }
        if(loc + 1 != i) {
            arr[loc + 1] = newitem;
            cmp.update(arr, loc + 1);
            if(!cmp.size()) {
                cout << 1 << endl;
                return 0;
            }
        }
    }
    if(!cmp.size()) cout << 1 << endl;
    else cout << 0 << endl;
}